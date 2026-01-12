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
        
        // Create pointer if it doesn't exist
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
            patchConnection.sendEventOrValue(this.param, this.value);
        }
    }
    
    updateNixieDisplay() {
        // Update nixie tube display if present
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
        
        // Update LED indicator
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
            const value = this.isActive ? 1 : 0;
            patchConnection.sendEventOrValue(this.param, value);
        }
    }
}

// ═══════════════════════════════════════════════════════════════
// VU METER ANIMATION
// ═══════════════════════════════════════════════════════════════

function updateVUMeter() {
    const vuMeter = document.getElementById('vu-meter');
    if (!vuMeter) return;
    
    // Simulate audio level (in real implementation, get from audio engine)
    // Random movement for demo purposes
    audioLevel += (Math.random() - 0.5) * 0.2;
    audioLevel = Math.max(0, Math.min(1, audioLevel));
    
    // Determine level category
    let levelCategory = 'low';
    if (audioLevel > 0.8) levelCategory = 'clip';
    else if (audioLevel > 0.6) levelCategory = 'high';
    else if (audioLevel > 0.3) levelCategory = 'mid';
    
    vuMeter.setAttribute('data-level', levelCategory);
    
    // Continue animation
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
            // Remove active from all
            keyButtons.forEach(btn => btn.classList.remove('active'));
            // Add active to clicked
            button.classList.add('active');
            
            // Send to engine
            if (patchConnection) {
                const key = parseInt(button.dataset.key);
                patchConnection.sendEventOrValue('arp_key', key);
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
            
            // Visual feedback
            button.style.transform = 'translateY(0)';
            setTimeout(() => {
                button.style.transform = '';
            }, 100);
            
            // Send to engine (implement variation logic)
            if (patchConnection) {
                patchConnection.sendEventOrValue('arp_variation', variation);
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
            
            // Visual feedback
            randomizeBtn.style.transform = 'scale(0.95)';
            setTimeout(() => {
                randomizeBtn.style.transform = '';
            }, 100);
            
            // Randomize pattern display
            const steps = document.querySelectorAll('.pattern-step');
            steps.forEach(step => {
                if (Math.random() > 0.5) {
                    step.classList.add('active');
                } else {
                    step.classList.remove('active');
                }
            });
            
            // Send to engine
            if (patchConnection) {
                patchConnection.sendEventOrValue('arp_randomize', 1);
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
            // Load preset (implement preset loading)
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
            // Implement preset saving
        });
    }
}

// ═══════════════════════════════════════════════════════════════
// MIDI NOTE HANDLING (for tape deck animation)
// ═══════════════════════════════════════════════════════════════

function handleMIDINote(noteOn) {
    if (noteOn) {
        startTapeDeck();
    } else {
        // Keep playing for a moment after note off
        setTimeout(() => {
            const activeNotes = 0; // Check if any notes are still playing
            if (activeNotes === 0) {
                stopTapeDeck();
            }
        }, 500);
    }
}

// ═══════════════════════════════════════════════════════════════
// INITIALIZATION
// ═══════════════════════════════════════════════════════════════

function initializeUI() {
    console.log('CINTA Vintage UI: Initializing...');
    
    // Initialize all knobs
    const knobs = document.querySelectorAll('.knob');
    knobs.forEach(knobElement => new Knob(knobElement));
    
    // Initialize all toggle buttons
    const toggleButtons = document.querySelectorAll('.toggle-btn');
    toggleButtons.forEach(buttonElement => new ToggleButton(buttonElement));
    
    // Initialize selectors
    const selects = document.querySelectorAll('select[data-param]');
    selects.forEach(select => {
        select.addEventListener('change', () => {
            if (patchConnection) {
                const value = parseFloat(select.value);
                patchConnection.sendEventOrValue(select.dataset.param, value);
            }
        });
    });
    
    // Initialize key selector
    initializeKeySelector();
    
    // Initialize variation buttons
    initializeVariationButtons();
    
    // Initialize randomize button
    initializeRandomizeButton();
    
    // Initialize preset browser
    initializePresetBrowser();
    
    console.log('CINTA Vintage UI: Initialized successfully');
}

// ═══════════════════════════════════════════════════════════════
// CMAJOR PATCH CONNECTION
// ═══════════════════════════════════════════════════════════════

window.addEventListener('load', async () => {
    initializeUI();
    
    if (window.cmajor) {
        try {
            patchConnection = await window.cmajor.createPatchConnection();
            
            if (patchConnection) {
                console.log('CINTA: Connected to Cmajor patch');
                
                // Send initial values to engine
                const knobs = document.querySelectorAll('.knob');
                knobs.forEach(knobElement => {
                    const knob = new Knob(knobElement);
                    knob.sendToEngine();
                });
                
                const toggleButtons = document.querySelectorAll('.toggle-btn');
                toggleButtons.forEach(buttonElement => {
                    const button = new ToggleButton(buttonElement);
                    button.sendToEngine();
                });
                
                const selects = document.querySelectorAll('select[data-param]');
                selects.forEach(select => {
                    const value = parseFloat(select.value);
                    patchConnection.sendEventOrValue(select.dataset.param, value);
                });
                
                // Listen for MIDI events to animate tape deck
                if (patchConnection.addEndpointListener) {
                    patchConnection.addEndpointListener('midiOut', (event) => {
                        if (event.message && event.message.type === 'noteOn') {
                            handleMIDINote(true);
                        } else if (event.message && event.message.type === 'noteOff') {
                            handleMIDINote(false);
                        }
                    });
                }
            }
        } catch (error) {
            console.error('CINTA: Failed to connect to patch:', error);
        }
    } else {
        console.log('CINTA: Running in standalone mode (no patch connection)');
        // Start demo animation
        startTapeDeck();
    }
});

window.addEventListener('beforeunload', () => {
    if (patchConnection) {
        patchConnection.disconnect();
    }
});

// ═══════════════════════════════════════════════════════════════
// DEMO MODE - Simulate activity when not connected to Cmajor
// ═══════════════════════════════════════════════════════════════

if (!window.cmajor) {
    // Simulate some activity for demo purposes
    setInterval(() => {
        // Random LED flicker
        const leds = document.querySelectorAll('.led-indicator');
        if (leds.length > 0 && Math.random() > 0.95) {
            const randomLed = leds[Math.floor(Math.random() * leds.length)];
            randomLed.classList.toggle('on');
        }
    }, 1000);
}
