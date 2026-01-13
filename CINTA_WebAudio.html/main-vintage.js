/* ═══════════════════════════════════════════════════════════════
   CINTA - 1975 HAVANA STUDIO VINTAGE UI - JAVASCRIPT
   Handles knob interactions, VU meter animation, tape reel animation,
   LED indicators, and Cmajor patch connection
   ═══════════════════════════════════════════════════════════════ */

let patchConnection = null;
let audioLevel = 0;
let isPlaying = false;

// ═══════════════════════════════════════════════════════════════
// KNOB CLASS - Chicken-Head Style Knobs
// ═══════════════════════════════════════════════════════════════

class Knob {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.min = parseFloat(element.dataset.min);
        this.max = parseFloat(element.dataset.max);
        this.value = parseFloat(element.dataset.value);
        this.curve = element.dataset.curve || 'linear';
        
        this.isDragging = false;
        this.startY = 0;
        this.startValue = 0;
        
        if (!this.element.querySelector('.knob-pointer')) {
            const pointer = document.createElement('div');
            pointer.className = 'knob-pointer';
            this.element.appendChild(pointer);
        }
        this.pointer = this.element.querySelector('.knob-pointer');
        
        this.element.addEventListener('mousedown', this.onMouseDown.bind(this));
        document.addEventListener('mousemove', this.onMouseMove.bind(this));
        document.addEventListener('mouseup', this.onMouseUp.bind(this));
        
        this.updateRotation();
    }
    
    onMouseDown(e) {
        this.isDragging = true;
        this.startY = e.clientY;
        this.startValue = this.value;
        e.preventDefault();
    }
    
    onMouseMove(e) {
        if (!this.isDragging) return;
        
        const delta = (this.startY - e.clientY) * 0.01;
        const range = this.max - this.min;
        let newValue = this.startValue + (delta * range);
        
        newValue = Math.max(this.min, Math.min(this.max, newValue));
        
        this.setValue(newValue);
    }
    
    onMouseUp() {
        this.isDragging = false;
    }
    
    setValue(value) {
        this.value = value;
        this.updateRotation();
        this.sendToEngine();
        this.updateNixieDisplay();
    }
    
    updateRotation() {
        const normalized = (this.value - this.min) / (this.max - this.min);
        const degrees = -135 + (normalized * 270);
        if (this.pointer) {
            this.pointer.style.transform = `translateX(-50%) rotate(${degrees}deg)`;
        }
    }
    
    sendToEngine() {
        if (patchConnection) {
            try {
                patchConnection.sendEventOrValue(this.param, this.value);
                
                // Macro knob mappings - control FM engine parameters
                if (this.param === 'vibe') {
                    patchConnection.sendEventOrValue('fm_depth', this.value);
                }
                else if (this.param === 'warmth') {
                    patchConnection.sendEventOrValue('fm_ratio', 0.5 + this.value * 8);
                }
                else if (this.param === 'space') {
                    patchConnection.sendEventOrValue('fm_level', this.value);
                }
                else if (this.param === 'movement') {
                    patchConnection.sendEventOrValue('fm_feedback', this.value);
                }
                else if (this.param === 'grit') {
                    patchConnection.sendEventOrValue('master_volume', 0.5 + this.value * 0.5);
                }
            } catch (error) {
                console.error(`Failed to send ${this.param}:`, error);
            }
        }
    }
    
    updateNixieDisplay() {
        const nixieDisplay = this.element.parentElement.querySelector('.nixie-display');
        if (nixieDisplay) {
            const digits = nixieDisplay.querySelectorAll('.nixie-digit');
            const valueStr = this.value.toFixed(1);
            const chars = valueStr.split('');
            
            digits.forEach((digit, index) => {
                if (index < chars.length) {
                    digit.textContent = chars[index];
                }
            });
        }
        
        // Update knob-value display
        const knobValue = this.element.parentElement.querySelector('.knob-value');
        if (knobValue) {
            const normalized = (this.value - this.min) / (this.max - this.min);
            const displayValue = Math.round(normalized * 100);
            knobValue.textContent = displayValue;
        }
    }
}

// ═══════════════════════════════════════════════════════════════
// TOGGLE BUTTON CLASS
// ═══════════════════════════════════════════════════════════════

class ToggleButton {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.knobParam = element.dataset.knobParam; // For texture rack toggles
        this.isActive = element.classList.contains('active');
        this.savedValue = 0.3; // Default value when turning on
        
        this.element.addEventListener('click', this.toggle.bind(this));
        
        this.updateLED();
    }
    
    toggle() {
        this.isActive = !this.isActive;
        
        if (this.isActive) {
            this.element.classList.add('active');
            this.element.textContent = 'ON';
        } else {
            this.element.classList.remove('active');
            this.element.textContent = 'OFF';
        }
        
        this.updateLED();
        this.sendToEngine();
    }
    
    updateLED() {
        const led = this.element.parentElement.querySelector('.led-indicator');
        if (led) {
            if (this.isActive) {
                led.classList.add('on');
            } else {
                led.classList.remove('on');
            }
        }
    }
    
    sendToEngine() {
        if (patchConnection) {
            try {
                // For texture rack toggles, control the knob parameter
                if (this.knobParam) {
                    // Get the knob element
                    const knob = this.element.parentElement.querySelector(`[data-param="${this.knobParam}"]`);
                    if (knob) {
                        const knobValue = parseFloat(knob.dataset.value) || 0.3;
                        this.savedValue = knobValue;
                    }
                    // Send 0 when OFF, saved value when ON
                    const value = this.isActive ? this.savedValue : 0.0;
                    console.log(`Toggle ${this.param}: ${this.isActive ? 'ON' : 'OFF'} → ${value}`);
                    patchConnection.sendEventOrValue(this.param, value);
                } else {
                    // Regular toggle (ON/OFF engines)
                    const value = this.isActive ? 1.0 : 0.0;
                    console.log(`Toggle ${this.param}: ${this.isActive ? 'ON' : 'OFF'} → ${value}`);
                    patchConnection.sendEventOrValue(this.param, value);
                }
            } catch (error) {
                console.error(`Failed to send ${this.param}:`, error);
            }
        }
    }
}

// ═══════════════════════════════════════════════════════════════
// VU METER ANIMATION
// ═══════════════════════════════════════════════════════════════

function updateVUMeter() {
    const vuMeter = document.getElementById('vu-meter');
    if (!vuMeter) return;
    
    audioLevel += (Math.random() - 0.5) * 0.2;
    audioLevel = Math.max(0, Math.min(1, audioLevel));
    
    let levelCategory = 'low';
    if (audioLevel > 0.8) levelCategory = 'clip';
    else if (audioLevel > 0.6) levelCategory = 'high';
    else if (audioLevel > 0.3) levelCategory = 'mid';
    
    vuMeter.setAttribute('data-level', levelCategory);
    
    if (isPlaying) {
        requestAnimationFrame(updateVUMeter);
    }
}

// ═══════════════════════════════════════════════════════════════
// TAPE DECK ANIMATION
// ═══════════════════════════════════════════════════════════════

function startTapeDeck() {
    const tapeDeck = document.getElementById('tape-deck');
    if (tapeDeck) {
        tapeDeck.classList.add('playing');
    }
    isPlaying = true;
    updateVUMeter();
}

function stopTapeDeck() {
    const tapeDeck = document.getElementById('tape-deck');
    if (tapeDeck) {
        tapeDeck.classList.remove('playing');
    }
    isPlaying = false;
}

// ═══════════════════════════════════════════════════════════════
// KEY SELECTOR
// ═══════════════════════════════════════════════════════════════

function initializeKeySelector() {
    const keyButtons = document.querySelectorAll('.key-btn');
    
    keyButtons.forEach(button => {
        button.addEventListener('click', () => {
            keyButtons.forEach(btn => btn.classList.remove('active'));
            button.classList.add('active');
            
            if (patchConnection) {
                try {
                    const key = parseInt(button.dataset.key);
                    patchConnection.sendEventOrValue('arp_key', key);
                } catch (error) {
                    console.error('Failed to send arp_key:', error);
                }
            }
        });
    });
}

// ═══════════════════════════════════════════════════════════════
// VARIATION BUTTONS
// ═══════════════════════════════════════════════════════════════

function initializeVariationButtons() {
    const varButtons = document.querySelectorAll('.var-btn');
    
    varButtons.forEach(button => {
        button.addEventListener('click', () => {
            const variation = button.dataset.variation;
            console.log('Variation:', variation);
            
            button.style.transform = 'translateY(0)';
            setTimeout(() => {
                button.style.transform = '';
            }, 100);
            
            if (patchConnection) {
                try {
                    patchConnection.sendEventOrValue('arp_variation', parseFloat(variation));
                } catch (error) {
                    console.error('Failed to send arp_variation:', error);
                }
            }
        });
    });
}

// ═══════════════════════════════════════════════════════════════
// RANDOMIZE BUTTON
// ═══════════════════════════════════════════════════════════════

function initializeRandomizeButton() {
    const randomizeBtn = document.getElementById('randomize');
    
    if (randomizeBtn) {
        randomizeBtn.addEventListener('click', () => {
            console.log('Randomize clicked');
            
            randomizeBtn.style.transform = 'scale(0.95)';
            setTimeout(() => {
                randomizeBtn.style.transform = '';
            }, 100);
            
            const steps = document.querySelectorAll('.pattern-step');
            steps.forEach(step => {
                if (Math.random() > 0.5) {
                    step.classList.add('active');
                } else {
                    step.classList.remove('active');
                }
            });
            
            if (patchConnection) {
                try {
                    patchConnection.sendEventOrValue('arp_randomize', 1.0);
                } catch (error) {
                    console.error('Failed to send arp_randomize:', error);
                }
            }
        });
    }
}

// ═══════════════════════════════════════════════════════════════
// PRESET BROWSER
// ═══════════════════════════════════════════════════════════════

function loadPreset(presetName) {
    if (!window.CINTA_PRESETS || !window.CINTA_PRESETS[presetName]) {
        console.warn('Preset not found:', presetName);
        return;
    }
    
    const preset = window.CINTA_PRESETS[presetName];
    console.log('Loading preset:', presetName, preset.category);
    
    // Send all-notes-off to stop any stuck notes
    if (patchConnection) {
        for (let note = 0; note < 128; note++) {
            try {
                patchConnection.sendMIDIInputEvent('noteOff', { pitch: note });
            } catch (e) {
                // Ignore errors
            }
        }
    }
    
    // Apply all preset parameters
    for (const [param, value] of Object.entries(preset)) {
        if (param === 'category') continue;
        
        try {
            patchConnection.sendEventOrValue(param, value);
            
            // Update UI knobs
            const knob = document.querySelector(`[data-param="${param}"]`);
            if (knob && knob.classList.contains('knob')) {
                knob.dataset.value = value;
                const knobInstance = knob.knobInstance;
                if (knobInstance) {
                    knobInstance.value = value;
                    knobInstance.updateRotation();
                }
            }
            
            // Update UI toggles
            if (knob && knob.classList.contains('toggle-btn')) {
                const isOn = value > 0.5;
                if (isOn) {
                    knob.classList.add('active');
                    knob.textContent = 'ON';
                } else {
                    knob.classList.remove('active');
                    knob.textContent = 'OFF';
                }
            }
            
            // Update UI selects
            const select = document.querySelector(`select[data-param="${param}"]`);
            if (select) {
                select.value = value;
            }
        } catch (e) {
            // Silently skip parameters that don't exist
        }
    }
    
    console.log('✅ Preset loaded:', presetName);
}

function initializePresetBrowser() {
    const presetSelect = document.getElementById('preset-select');
    const prevBtn = document.querySelector('.preset-btn.prev');
    const nextBtn = document.querySelector('.preset-btn.next');
    const saveBtn = document.querySelector('.preset-btn.save');
    
    if (presetSelect) {
        presetSelect.addEventListener('change', () => {
            const presetName = presetSelect.value;
            console.log('Preset changed:', presetName);
            loadPreset(presetName);
        });
    }
    
    if (prevBtn) {
        prevBtn.addEventListener('click', () => {
            if (presetSelect) {
                const currentIndex = presetSelect.selectedIndex;
                if (currentIndex > 0) {
                    presetSelect.selectedIndex = currentIndex - 1;
                    presetSelect.dispatchEvent(new Event('change'));
                }
            }
        });
    }
    
    if (nextBtn) {
        nextBtn.addEventListener('click', () => {
            if (presetSelect) {
                const currentIndex = presetSelect.selectedIndex;
                if (currentIndex < presetSelect.options.length - 1) {
                    presetSelect.selectedIndex = currentIndex + 1;
                    presetSelect.dispatchEvent(new Event('change'));
                }
            }
        });
    }
    
    if (saveBtn) {
        saveBtn.addEventListener('click', () => {
            console.log('Save preset');
        });
    }
}

// ═══════════════════════════════════════════════════════════════
// INITIALIZATION
// ═══════════════════════════════════════════════════════════════

function initializeUI() {
    console.log('CINTA Vintage UI: Initializing...');
    
    patchConnection = window.patchConnection;
    
    const knobs = document.querySelectorAll('.knob');
    knobs.forEach(knobElement => new Knob(knobElement));
    
    const toggleButtons = document.querySelectorAll('.toggle-btn');
    toggleButtons.forEach(buttonElement => new ToggleButton(buttonElement));
    
    const selects = document.querySelectorAll('select[data-param]');
    selects.forEach(select => {
        select.addEventListener('change', () => {
            if (patchConnection) {
                try {
                    const value = parseFloat(select.value);
                    patchConnection.sendEventOrValue(select.dataset.param, value);
                } catch (error) {
                    console.error(`Failed to send ${select.dataset.param}:`, error);
                }
            }
        });
    });
    
    initializeKeySelector();
    initializeVariationButtons();
    initializeRandomizeButton();
    initializePresetBrowser();
    
    if (patchConnection) {
        console.log('✅ CINTA: Connected to Cmajor patch');
        
        // Enable FM engine by default for immediate sound
        console.log('CINTA: Enabling FM engine...');
        patchConnection.sendEventOrValue('fm_on', 1.0);
        patchConnection.sendEventOrValue('fm_level', 0.7);
        
        patchConnection.sendEventOrValue('master_volume', 0.8);
        
        console.log('CINTA: Sending initial parameter values...');
        knobs.forEach(knobElement => {
            const param = knobElement.dataset.param;
            const value = parseFloat(knobElement.dataset.value);
            if (param) {
                try {
                    patchConnection.sendEventOrValue(param, value);
                } catch (e) {
                    console.warn(`Could not send ${param}`);
                }
            }
        });
        
        toggleButtons.forEach(buttonElement => {
            const param = buttonElement.dataset.param;
            const isActive = buttonElement.classList.contains('active');
            if (param) {
                try {
                    patchConnection.sendEventOrValue(param, isActive ? 1.0 : 0.0);
                } catch (e) {
                    console.warn(`Could not send ${param}`);
                }
            }
        });
        
        selects.forEach(select => {
            const param = select.dataset.param;
            const value = parseFloat(select.value);
            if (param) {
                try {
                    patchConnection.sendEventOrValue(param, value);
                } catch (e) {
                    console.warn(`Could not send ${param}`);
                }
            }
        });
        
        console.log('✅ CINTA: All initial values sent');
        
        startTapeDeck();
    } else {
        console.log('CINTA: Running in standalone mode (no Cmajor API)');
        startTapeDeck();
    }
    
    console.log('CINTA Vintage UI: Initialized successfully');
}

initializeUI();
