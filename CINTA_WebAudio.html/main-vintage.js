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
                patchConnection.sendParameterValue(this.param, this.value);
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
    }
}

// ═══════════════════════════════════════════════════════════════
// TOGGLE BUTTON CLASS
// ═══════════════════════════════════════════════════════════════

class ToggleButton {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.isActive = element.classList.contains('active');
        
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
                const value = this.isActive ? 1.0 : 0.0;
                patchConnection.sendParameterValue(this.param, value);
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
                    patchConnection.sendParameterValue('arp_key', key);
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
                    patchConnection.sendParameterValue('arp_variation', parseFloat(variation));
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
                    patchConnection.sendParameterValue('arp_randomize', 1.0);
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

function initializePresetBrowser() {
    const presetSelect = document.getElementById('preset-select');
    const prevBtn = document.querySelector('.preset-btn.prev');
    const nextBtn = document.querySelector('.preset-btn.next');
    const saveBtn = document.querySelector('.preset-btn.save');
    
    if (presetSelect) {
        presetSelect.addEventListener('change', () => {
            console.log('Preset changed:', presetSelect.value);
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
                    patchConnection.sendParameterValue(select.dataset.param, value);
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
        
        console.log('CINTA: Sending initial parameter values...');
        knobs.forEach(knobElement => {
            const param = knobElement.dataset.param;
            const value = parseFloat(knobElement.dataset.value);
            if (param) {
                try {
                    patchConnection.sendParameterValue(param, value);
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
                    patchConnection.sendParameterValue(param, isActive ? 1.0 : 0.0);
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
                    patchConnection.sendParameterValue(param, value);
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
