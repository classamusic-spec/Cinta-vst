// CINTA Vintage Keyboard Component
// 1975 Havana Style Piano Interface

class VintageKeyboard {
    constructor(container, patchConnection) {
        this.container = container;
        this.patchConnection = patchConnection;
        this.activeNotes = new Set();
        this.octaveOffset = 4; // Start at C4 (middle C)
        
        // Keyboard layout: 3.5+ octaves (C to A) - Full width to match synth unit
        this.keys = this.generateKeys(48, 93); // C2 to A5 (46 keys)
        
        // Computer keyboard mapping
        this.keyboardMap = {
            'KeyA': 60,  // C
            'KeyW': 61,  // C#
            'KeyS': 62,  // D
            'KeyE': 63,  // D#
            'KeyD': 64,  // E
            'KeyF': 65,  // F
            'KeyT': 66,  // F#
            'KeyG': 67,  // G
            'KeyY': 68,  // G#
            'KeyH': 69,  // A
            'KeyU': 70,  // A#
            'KeyJ': 71,  // B
            'KeyK': 72,  // C (octave up)
            'KeyO': 73,  // C#
            'KeyL': 74   // D
        };
        
        this.render();
        this.attachEventListeners();
        this.attachComputerKeyboard();
    }
    
    generateKeys(startMidi, endMidi) {
        const keys = [];
        const noteNames = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];
        
        for (let midi = startMidi; midi <= endMidi; midi++) {
            const noteIndex = midi % 12;
            const noteName = noteNames[noteIndex];
            const isBlack = noteName.includes('#');
            
            keys.push({
                note: midi - startMidi,
                name: noteName,
                type: isBlack ? 'black' : 'white',
                midi: midi
            });
        }
        
        return keys;
    }
    
    render() {
        this.container.innerHTML = `
            <div class="vintage-keyboard-wrapper">
                <div class="vintage-keyboard-controls">
                    <button class="vintage-btn octave-down" data-action="octave-down">
                        <span class="vintage-label">OCTAVE</span>
                        <span class="vintage-symbol">▼</span>
                    </button>
                    <div class="octave-display">
                        <span class="vintage-label">OCT</span>
                        <span class="octave-value">${this.octaveOffset}</span>
                    </div>
                    <button class="vintage-btn octave-up" data-action="octave-up">
                        <span class="vintage-label">OCTAVE</span>
                        <span class="vintage-symbol">▲</span>
                    </button>
                </div>
                <div class="vintage-keyboard">
                    ${this.renderKeys()}
                </div>
                <div class="vintage-keyboard-footer">
                    <div class="vintage-logo">CINTA</div>
                    <div class="vintage-model">Vintage Texture Machine</div>
                    <div class="vintage-year">Est. 1975 • Havana</div>
                </div>
            </div>
        `;
    }
    
    renderKeys() {
        const whiteKeys = this.keys.filter(k => k.type === 'white');
        const blackKeys = this.keys.filter(k => k.type === 'black');
        
        const whiteKeyWidthPercent = 3.7;
        const blackKeyOffsetPercent = 2.7;
        
        let html = '<div class="keys-container">';
        
        // Render white keys
        whiteKeys.forEach((key, index) => {
            html += `
                <div class="key white-key" 
                     data-note="${key.midi}" 
                     data-name="${key.name}"
                     style="left: ${index * whiteKeyWidthPercent}%;">
                    <div class="key-surface"></div>
                    <div class="key-label">${key.name}</div>
                    <div class="key-glow"></div>
                </div>
            `;
        });
        
        // Render black keys (positioned absolutely over white keys)
        blackKeys.forEach(key => {
            const whiteKeyIndex = this.getWhiteKeyIndexBefore(key.note);
            const leftPos = (whiteKeyIndex * whiteKeyWidthPercent) + blackKeyOffsetPercent;
            
            html += `
                <div class="key black-key" 
                     data-note="${key.midi}" 
                     data-name="${key.name}"
                     style="left: ${leftPos}%;">
                    <div class="key-surface"></div>
                    <div class="key-glow"></div>
                </div>
            `;
        });
        
        html += '</div>';
        return html;
    }
    
    getWhiteKeyIndexBefore(noteIndex) {
        const whiteKeysBeforePattern = [0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6];
        const octave = Math.floor(noteIndex / 12);
        const noteInOctave = noteIndex % 12;
        return (octave * 7) + whiteKeysBeforePattern[noteInOctave];
    }
    
    attachEventListeners() {
        // Key press/release
        this.container.querySelectorAll('.key').forEach(keyEl => {
            keyEl.addEventListener('mousedown', (e) => this.handleKeyDown(e));
            keyEl.addEventListener('mouseup', (e) => this.handleKeyUp(e));
            keyEl.addEventListener('mouseleave', (e) => this.handleKeyUp(e));
            keyEl.addEventListener('touchstart', (e) => {
                e.preventDefault();
                this.handleKeyDown(e);
            });
            keyEl.addEventListener('touchend', (e) => {
                e.preventDefault();
                this.handleKeyUp(e);
            });
        });
        
        // Octave controls
        this.container.querySelector('[data-action="octave-up"]')?.addEventListener('click', () => {
            this.octaveOffset = Math.min(7, this.octaveOffset + 1);
            this.updateOctaveDisplay();
        });
        
        this.container.querySelector('[data-action="octave-down"]')?.addEventListener('click', () => {
            this.octaveOffset = Math.max(0, this.octaveOffset - 1);
            this.updateOctaveDisplay();
        });
    }
    
    handleKeyDown(e) {
        const keyEl = e.currentTarget;
        const midiNote = parseInt(keyEl.dataset.note);
        
        if (this.activeNotes.has(midiNote)) return;
        
        this.activeNotes.add(midiNote);
        keyEl.classList.add('active');
        
        // Send MIDI note on
        if (this.patchConnection) {
            this.patchConnection.sendEventOrValue('noteOn', {
                pitch: midiNote,
                velocity: 1.0
            });
        }
    }
    
    handleKeyUp(e) {
        const keyEl = e.currentTarget;
        const midiNote = parseInt(keyEl.dataset.note);
        
        if (!this.activeNotes.has(midiNote)) return;
        
        this.activeNotes.delete(midiNote);
        keyEl.classList.remove('active');
        
        // Send MIDI note off
        if (this.patchConnection) {
            this.patchConnection.sendEventOrValue('noteOff', {
                pitch: midiNote,
                velocity: 0.0
            });
        }
    }
    
    attachComputerKeyboard() {
        this.pressedKeys = new Set();
        
        this.keyDownHandler = (e) => {
            if (e.repeat) return;
            
            const midiNote = this.keyboardMap[e.code];
            if (midiNote !== undefined && !this.pressedKeys.has(e.code)) {
                this.pressedKeys.add(e.code);
                
                // Find and activate the visual key
                const keyEl = this.container.querySelector(`[data-note="${midiNote}"]`);
                if (keyEl) {
                    keyEl.classList.add('active');
                }
                
                this.activeNotes.add(midiNote);
                
                // Send MIDI note on
                if (this.patchConnection) {
                    this.patchConnection.sendEventOrValue('noteOn', {
                        pitch: midiNote,
                        velocity: 1.0
                    });
                }
            }
        };
        
        this.keyUpHandler = (e) => {
            const midiNote = this.keyboardMap[e.code];
            if (midiNote !== undefined && this.pressedKeys.has(e.code)) {
                this.pressedKeys.delete(e.code);
                
                // Find and deactivate the visual key
                const keyEl = this.container.querySelector(`[data-note="${midiNote}"]`);
                if (keyEl) {
                    keyEl.classList.remove('active');
                }
                
                this.activeNotes.delete(midiNote);
                
                // Send MIDI note off
                if (this.patchConnection) {
                    this.patchConnection.sendEventOrValue('noteOff', {
                        pitch: midiNote,
                        velocity: 0.0
                    });
                }
            }
        };
        
        window.addEventListener('keydown', this.keyDownHandler);
        window.addEventListener('keyup', this.keyUpHandler);
    }
    
    updateOctaveDisplay() {
        const display = this.container.querySelector('.octave-value');
        if (display) {
            display.textContent = this.octaveOffset;
        }
    }
    
    destroy() {
        // Remove computer keyboard listeners
        if (this.keyDownHandler) {
            window.removeEventListener('keydown', this.keyDownHandler);
        }
        if (this.keyUpHandler) {
            window.removeEventListener('keyup', this.keyUpHandler);
        }
        
        // Release all active notes
        this.activeNotes.forEach(note => {
            if (this.patchConnection) {
                this.patchConnection.sendEventOrValue('noteOff', {
                    pitch: note,
                    velocity: 0.0
                });
            }
        });
        this.activeNotes.clear();
        this.pressedKeys.clear();
    }
}

// Export for use in main app
window.VintageKeyboard = VintageKeyboard;
