let patchConnection = null;
let currentComplexity = 5;

const tapeSoundNames = ['Strings', 'Flutes', 'Choirs', 'Brass', 'Keys'];
const waveNames = ['Saw', 'Square', 'Pulse', 'Triangle'];
const rateNames = ['1/1', '1/2', '1/4', '1/8', '1/16', '1/32', '1/4T', '1/8T', '1/16T'];

const melodyPatterns = [
    [1, 0, 7, 0, 1, 0, 7, 0, 1, 0, 7, 0, 1, 0, 7, 0],
    [5, 0, 4, 0, 3, 0, 1, 0, 5, 0, 4, 0, 3, 0, 1, 0],
    [1, 0, 3, 0, 5, 0, 0, 0, 1, 0, 3, 0, 5, 0, 0, 0],
    [1, 0, 5, 0, 7, 0, 5, 0, 1, 0, 5, 0, 7, 0, 5, 0],
    [1, 0, 3, 0, 5, 0, 6, 0, 5, 0, 3, 0, 1, 0, 0, 0],
    [1, 1, 0, 7, 0, 5, 0, 0, 1, 1, 0, 7, 0, 5, 0, 0],
    [5, 0, 6, 0, 7, 0, 1, 7, 5, 0, 6, 0, 7, 0, 1, 7],
    [1, 0, 2, 0, 1, 0, 7, 0, 1, 0, 2, 0, 1, 0, 7, 0],
    [1, 0, 3, 0, 4, 0, 5, 0, 7, 0, 5, 0, 4, 0, 3, 0],
    [1, 1, 0, 3, 0, 1, 0, 0, 1, 1, 0, 3, 0, 1, 0, 0],
    [1, 0, 3, 0, 4, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 3, 0, 5, 0, 6, 0, 5, 0, 3, 0, 1, 0, 0, 0],
    [1, 0, 5, 0, 1, 0, 5, 0, 7, 0, 5, 0, 1, 0, 0, 0],
    [1, 0, 2, 0, 3, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0]
];

const rhythmPatterns = [
    [100, 0, 0, 80, 0, 0, 100, 0, 0, 80, 0, 0, 100, 0, 0, 80],
    [100, 0, 60, 90, 0, 60, 100, 0, 60, 90, 0, 60, 100, 0, 60, 90],
    [100, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [80, 0, 0, 60, 0, 0, 70, 0, 0, 60, 0, 0, 80, 0, 0, 60],
    [100, 0, 100, 0, 80, 0, 100, 0, 100, 0, 80, 0, 100, 0, 100, 0],
    [70, 0, 0, 60, 0, 0, 70, 0, 0, 60, 0, 0, 70, 0, 0, 60],
    [100, 50, 0, 100, 0, 50, 100, 0, 0, 100, 50, 0, 100, 0, 50, 0],
    [100, 0, 0, 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0, 0],
    [60, 60, 60, 80, 60, 60, 60, 80, 60, 60, 100, 80, 60, 60, 60, 80],
    [100, 0, 60, 0, 80, 0, 60, 0, 100, 0, 60, 0, 80, 60, 0, 60],
    [100, 0, 0, 100, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [100, 0, 0, 100, 0, 0, 0, 100, 0, 0, 100, 0, 100, 0, 0, 0]
];

const scales = [
    [0, 2, 3, 5, 7, 8, 10],
    [0, 2, 4, 5, 7, 9, 11],
    [0, 2, 3, 5, 7, 8, 11],
    [0, 2, 4, 7, 9],
    [0, 2, 3, 5, 7, 9, 10],
    [0, 3, 5, 7, 10],
    [0, 2, 4, 5, 7, 9, 11],
    [0, 1, 4, 5, 7, 8, 10]
];

const noteNames = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];

let currentMelodyPattern = [...melodyPatterns[0]];
let currentRhythmPattern = [...rhythmPatterns[0]];

class Knob {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.min = parseFloat(element.dataset.min);
        this.max = parseFloat(element.dataset.max);
        this.value = parseFloat(element.dataset.value);
        this.isDiscrete = element.classList.contains('discrete');
        
        this.isDragging = false;
        this.startY = 0;
        this.startValue = 0;
        
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
        
        if (this.isDiscrete) {
            newValue = Math.round(newValue);
        }
        
        this.setValue(newValue);
    }
    
    onMouseUp() {
        this.isDragging = false;
    }
    
    setValue(value) {
        this.value = value;
        this.updateRotation();
        this.sendToEngine();
        this.updateDisplay();
    }
    
    updateRotation() {
        const normalized = (this.value - this.min) / (this.max - this.min);
        const degrees = -135 + (normalized * 270);
        this.element.style.transform = `rotate(${degrees}deg)`;
    }
    
    sendToEngine() {
        if (patchConnection) {
            patchConnection.sendEventOrValue(this.param, this.value);
        }
    }
    
    updateDisplay() {
        const control = this.element.closest('.knob-control');
        if (!control) return;
        
        const valueDisplay = control.querySelector('.value-display');
        if (valueDisplay) {
            if (this.param === 'tape_sound') {
                valueDisplay.textContent = tapeSoundNames[Math.round(this.value)] || '';
            } else if (this.param.includes('wave')) {
                valueDisplay.textContent = waveNames[Math.round(this.value)] || '';
            } else if (this.param === 'arp_rate') {
                valueDisplay.textContent = rateNames[Math.round(this.value)] || '';
            } else if (this.param === 'arp_swing' || this.param === 'arp_gate') {
                valueDisplay.textContent = Math.round(this.value) + '%';
            } else if (this.param === 'arp_humanize') {
                valueDisplay.textContent = Math.round(this.value * 100) + '%';
            } else if (this.param === 'arp_octaves') {
                valueDisplay.textContent = Math.round(this.value);
            }
        }
    }
}

class Toggle {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.element.addEventListener('change', this.onChange.bind(this));
    }
    
    onChange() {
        const value = this.element.checked ? 1 : 0;
        if (patchConnection) {
            patchConnection.sendEventOrValue(this.param, value);
        }
    }
}

class Selector {
    constructor(element) {
        this.element = element;
        this.param = element.dataset.param;
        this.element.addEventListener('change', this.onChange.bind(this));
    }
    
    onChange() {
        const value = parseFloat(this.element.value);
        if (patchConnection) {
            patchConnection.sendEventOrValue(this.param, value);
        }
        
        if (this.param === 'arp_melody_type') {
            currentMelodyPattern = [...melodyPatterns[Math.round(value)]];
            updatePatternDisplay();
        } else if (this.param === 'arp_rhythm_type') {
            currentRhythmPattern = [...rhythmPatterns[Math.round(value)]];
            updatePatternDisplay();
        } else if (this.param === 'arp_scale' || this.param === 'arp_key') {
            updatePatternDisplay();
        }
    }
}

function updatePatternDisplay() {
    const steps = document.querySelectorAll('.pattern-step');
    const keySelect = document.querySelector('select[data-param="arp_key"]');
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    
    const key = keySelect ? parseInt(keySelect.value) : 0;
    const scaleIndex = scaleSelect ? parseInt(scaleSelect.value) : 0;
    const scale = scales[scaleIndex];
    
    steps.forEach((step, index) => {
        const velocity = currentRhythmPattern[index];
        const scaleDegree = currentMelodyPattern[index];
        
        if (velocity > 0 && scaleDegree > 0) {
            step.classList.add('active');
            
            const degree = (scaleDegree - 1) % scale.length;
            const octaveOffset = Math.floor((scaleDegree - 1) / scale.length) * 12;
            const noteOffset = scale[degree] + octaveOffset;
            const midiNote = (key + 48 + noteOffset) % 12;
            const noteName = noteNames[midiNote];
            
            const noteLabel = step.querySelector('.note-label');
            if (noteLabel) {
                noteLabel.textContent = noteName;
            }
        } else {
            step.classList.remove('active');
            const noteLabel = step.querySelector('.note-label');
            if (noteLabel) {
                noteLabel.textContent = '';
            }
        }
    });
}

function initializeUI() {
    const knobs = document.querySelectorAll('.knob');
    knobs.forEach(knobElement => new Knob(knobElement));
    
    const toggles = document.querySelectorAll('input[type="checkbox"][data-param]');
    toggles.forEach(toggleElement => new Toggle(toggleElement));
    
    const selectors = document.querySelectorAll('select[data-param]');
    selectors.forEach(selectorElement => new Selector(selectorElement));
    
    const randomizeBtn = document.getElementById('randomize-btn');
    if (randomizeBtn) {
        randomizeBtn.addEventListener('click', smartRandomize);
    }
    
    const complexityDots = document.querySelectorAll('.dot');
    complexityDots.forEach(dot => {
        dot.addEventListener('click', () => {
            const complexity = parseInt(dot.dataset.complexity);
            setComplexity(complexity);
        });
    });
    
    const variationBtns = document.querySelectorAll('.variation-btn');
    variationBtns.forEach(btn => {
        btn.addEventListener('click', () => {
            const variation = btn.dataset.variation;
            applyVariation(variation);
        });
    });
    
    updatePatternDisplay();
}

function setComplexity(value) {
    currentComplexity = value;
    const dots = document.querySelectorAll('.dot');
    dots.forEach((dot, index) => {
        if (index < value) {
            dot.classList.add('active');
        } else {
            dot.classList.remove('active');
        }
    });
    
    if (patchConnection) {
        patchConnection.sendEventOrValue('arp_complexity', value);
    }
}

function smartRandomize() {
    const modeSelect = document.getElementById('randomize-mode');
    const mode = modeSelect ? parseInt(modeSelect.value) : 0;
    
    const keySelect = document.querySelector('select[data-param="arp_key"]');
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    
    if (mode === 0) {
        generateHitmaker();
    } else if (mode === 1) {
        generateVibras();
    } else if (mode === 2) {
        generateEmociones();
    } else if (mode === 3) {
        generateAltura();
    } else if (mode === 4) {
        generatePerreo();
    } else {
        generateExperimental();
    }
    
    if (keySelect) {
        const randomKey = Math.floor(Math.random() * 12);
        keySelect.value = randomKey;
        keySelect.dispatchEvent(new Event('change'));
    }
    
    updatePatternDisplay();
}

function generateHitmaker() {
    const noteCount = Math.min(2 + Math.floor(currentComplexity / 3), 4);
    const availableNotes = [1, 3, 5];
    
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = new Array(16).fill(0);
    
    for (let i = 0; i < 16; i += Math.floor(16 / noteCount)) {
        if (i < 16) {
            currentMelodyPattern[i] = availableNotes[Math.floor(Math.random() * availableNotes.length)];
            currentRhythmPattern[i] = 80 + Math.floor(Math.random() * 20);
        }
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = Math.random() > 0.5 ? 0 : 1;
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function generateVibras() {
    const noteCount = Math.min(2, 1 + Math.floor(currentComplexity / 5));
    
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = new Array(16).fill(0);
    
    currentMelodyPattern[0] = 1;
    currentRhythmPattern[0] = 100;
    
    if (noteCount > 1) {
        currentMelodyPattern[8] = Math.random() > 0.5 ? 5 : 3;
        currentRhythmPattern[8] = 80;
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = 0;
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function generateEmociones() {
    const noteCount = Math.min(4 + Math.floor(currentComplexity / 2), 6);
    const availableNotes = [1, 2, 3, 4, 5, 6, 7];
    
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = new Array(16).fill(0);
    
    for (let i = 0; i < noteCount; i++) {
        const pos = Math.floor((i / noteCount) * 16);
        currentMelodyPattern[pos] = availableNotes[Math.floor(Math.random() * availableNotes.length)];
        currentRhythmPattern[pos] = 70 + Math.floor(Math.random() * 30);
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = Math.random() > 0.5 ? 0 : 2;
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function generateAltura() {
    const noteCount = Math.min(3 + Math.floor(currentComplexity / 2), 5);
    const availableNotes = [1, 3, 5, 6];
    
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = new Array(16).fill(0);
    
    for (let i = 0; i < noteCount; i++) {
        const pos = Math.floor((i / noteCount) * 16);
        currentMelodyPattern[pos] = availableNotes[Math.floor(Math.random() * availableNotes.length)];
        currentRhythmPattern[pos] = 80 + Math.floor(Math.random() * 20);
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = 1;
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function generatePerreo() {
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = [...rhythmPatterns[4]];
    
    for (let i = 0; i < 16; i++) {
        if (currentRhythmPattern[i] > 0) {
            currentMelodyPattern[i] = Math.random() > 0.5 ? 1 : 5;
        }
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = 5;
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function generateExperimental() {
    currentMelodyPattern = new Array(16).fill(0);
    currentRhythmPattern = new Array(16).fill(0);
    
    for (let i = 0; i < 16; i++) {
        if (Math.random() < (currentComplexity / 10)) {
            currentMelodyPattern[i] = 1 + Math.floor(Math.random() * 7);
            currentRhythmPattern[i] = 60 + Math.floor(Math.random() * 40);
        }
    }
    
    const scaleSelect = document.querySelector('select[data-param="arp_scale"]');
    if (scaleSelect) {
        scaleSelect.value = Math.floor(Math.random() * 8);
        scaleSelect.dispatchEvent(new Event('change'));
    }
}

function applyVariation(type) {
    switch(type) {
        case 'octave-up':
            currentMelodyPattern = currentMelodyPattern.map(n => n > 0 ? n + 7 : 0);
            break;
        case 'octave-down':
            currentMelodyPattern = currentMelodyPattern.map(n => n > 7 ? n - 7 : n);
            break;
        case 'invert':
            const max = Math.max(...currentMelodyPattern);
            currentMelodyPattern = currentMelodyPattern.map(n => n > 0 ? max - n + 1 : 0);
            break;
        case 'reverse':
            currentMelodyPattern.reverse();
            currentRhythmPattern.reverse();
            break;
        case 'simplify':
            for (let i = 1; i < 16; i += 2) {
                currentMelodyPattern[i] = 0;
                currentRhythmPattern[i] = 0;
            }
            break;
        case 'double':
            const newMelody = [];
            const newRhythm = [];
            for (let i = 0; i < 8; i++) {
                newMelody.push(currentMelodyPattern[i], currentMelodyPattern[i]);
                newRhythm.push(currentRhythmPattern[i], currentRhythmPattern[i]);
            }
            currentMelodyPattern = newMelody;
            currentRhythmPattern = newRhythm;
            break;
        case 'shift-left':
            currentMelodyPattern.unshift(currentMelodyPattern.pop());
            currentRhythmPattern.unshift(currentRhythmPattern.pop());
            break;
        case 'shift-right':
            currentMelodyPattern.push(currentMelodyPattern.shift());
            currentRhythmPattern.push(currentRhythmPattern.shift());
            break;
    }
    
    updatePatternDisplay();
}

window.addEventListener('load', async () => {
    initializeUI();
    
    if (window.cmajor) {
        try {
            patchConnection = await window.cmajor.createPatchConnection();
            
            if (patchConnection) {
                console.log('CINTA: Connected to patch');
                
                const knobs = document.querySelectorAll('.knob');
                knobs.forEach(knobElement => {
                    const knob = new Knob(knobElement);
                    knob.sendToEngine();
                });
                
                const toggles = document.querySelectorAll('input[type="checkbox"][data-param]');
                toggles.forEach(toggleElement => {
                    const value = toggleElement.checked ? 1 : 0;
                    patchConnection.sendEventOrValue(toggleElement.dataset.param, value);
                });
                
                const selectors = document.querySelectorAll('select[data-param]');
                selectors.forEach(selectorElement => {
                    const value = parseFloat(selectorElement.value);
                    patchConnection.sendEventOrValue(selectorElement.dataset.param, value);
                });
            }
        } catch (error) {
            console.error('CINTA: Failed to connect to patch:', error);
        }
    } else {
        console.log('CINTA: Running in standalone mode (no patch connection)');
    }
});

window.addEventListener('beforeunload', () => {
    if (patchConnection) {
        patchConnection.disconnect();
    }
});
