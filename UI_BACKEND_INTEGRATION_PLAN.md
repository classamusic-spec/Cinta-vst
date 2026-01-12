# CINTA UI-Backend Integration Plan

## Current Situation

**UI Status:**
- ✅ Vintage UI complete and displays beautifully
- ✅ All knobs, controls, and animations working
- ✅ Size modes functional (FULL, COMPACT, MINI, STRIP)
- ❌ Not connected to Cmajor backend
- ❌ Parameters don't control the synth

**Backend Status:**
- ✅ CINTA.cmajor compiles and runs
- ✅ 8-voice polyphony working
- ✅ All 3 engines functional (FM, Tape, Analog)
- ✅ All parameters defined and working via MIDI
- ❌ UI can't send parameter changes to synth

## The Problem

The UI JavaScript (`main-vintage.js`) has code to connect to Cmajor:
```javascript
if (patchConnection) {
    patchConnection.sendEventOrValue(this.param, this.value);
}
```

But `patchConnection` is null because:
1. The UI is opened in a standalone browser (no Cmajor connection)
2. When opened via `cmaj play`, the connection needs to be established
3. The Cmajor patch connection API needs to be initialized

## The Solution: 3 Approaches

### Approach 1: Cmajor Embedded View (Recommended)

**How it works:**
- Cmajor player loads the HTML UI inside its window
- Provides `window.cmajor` API for parameter communication
- UI sends parameter changes directly to the patch

**Implementation Steps:**

1. **Update main-vintage.js to detect Cmajor environment:**
```javascript
// Check if running in Cmajor player
if (window.cmajor) {
    console.log('Running in Cmajor player');
    initializeCmajorConnection();
} else {
    console.log('Running in standalone browser (demo mode)');
}
```

2. **Initialize Cmajor connection:**
```javascript
async function initializeCmajorConnection() {
    try {
        patchConnection = await window.cmajor.createPatchConnection();
        
        // Get list of all parameters
        const params = await patchConnection.getParameters();
        console.log('Available parameters:', params);
        
        // Set up parameter listeners
        patchConnection.addParameterListener((param, value) => {
            updateUIFromParameter(param, value);
        });
        
    } catch (error) {
        console.error('Failed to connect to Cmajor:', error);
    }
}
```

3. **Update sendToEngine method:**
```javascript
sendToEngine() {
    if (patchConnection) {
        try {
            patchConnection.sendParameterValue(this.param, this.value);
        } catch (error) {
            console.error('Failed to send parameter:', error);
        }
    }
}
```

4. **Fix CINTA.cmajorpatch view configuration:**
```json
{
    "view": {
        "src": "ui/index-vintage.html",
        "width": 900,
        "height": 500,
        "resizable": true
    }
}
```

**Pros:**
- ✅ Direct parameter control
- ✅ Bi-directional communication (UI ↔ Synth)
- ✅ Real-time parameter updates
- ✅ Works in Cmajor player

**Cons:**
- ❌ Only works when opened via `cmaj play`
- ❌ Doesn't work in standalone browser

---

### Approach 2: WebSocket Bridge

**How it works:**
- Cmajor patch runs in background
- Separate WebSocket server bridges UI to patch
- UI connects via WebSocket to send/receive parameters

**Implementation Steps:**

1. **Create WebSocket server (Node.js):**
```javascript
const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', (ws) => {
    ws.on('message', (message) => {
        const { param, value } = JSON.parse(message);
        // Forward to Cmajor via OSC or MIDI
    });
});
```

2. **Update UI to connect via WebSocket:**
```javascript
const ws = new WebSocket('ws://localhost:8080');
ws.onopen = () => {
    console.log('Connected to CINTA backend');
};

function sendToEngine() {
    if (ws.readyState === WebSocket.OPEN) {
        ws.send(JSON.stringify({
            param: this.param,
            value: this.value
        }));
    }
}
```

**Pros:**
- ✅ Works in any browser
- ✅ Can run UI remotely
- ✅ Multiple UIs can connect

**Cons:**
- ❌ Requires separate server
- ❌ More complex setup
- ❌ Additional latency

---

### Approach 3: OSC/MIDI Control

**How it works:**
- UI sends OSC or MIDI messages
- Cmajor patch receives MIDI CC or OSC
- Map UI controls to MIDI CC numbers

**Implementation Steps:**

1. **Map parameters to MIDI CC:**
```javascript
const parameterCCMap = {
    'vibe': 1,
    'warmth': 2,
    'space': 3,
    'movement': 4,
    'grit': 5,
    'fm_ratio': 10,
    'fm_depth': 11,
    // ... etc
};
```

2. **Send MIDI CC from UI:**
```javascript
function sendToEngine() {
    const cc = parameterCCMap[this.param];
    if (cc && midiOutput) {
        const midiValue = Math.floor(this.value * 127);
        midiOutput.send([0xB0, cc, midiValue]);
    }
}
```

3. **Update CINTA.cmajor to receive MIDI CC:**
```cmajor
input event std::midi::Message midiCC;

event midiCC(std::midi::Message m) {
    if (m.isController()) {
        let cc = m.getController();
        let value = float(m.getControllerValue()) / 127.0f;
        
        if (cc == 1) param_vibe = value;
        else if (cc == 2) param_warmth = value;
        // ... etc
    }
}
```

**Pros:**
- ✅ Standard MIDI protocol
- ✅ Works with hardware controllers
- ✅ Can use existing MIDI tools

**Cons:**
- ❌ Limited to 128 values per parameter
- ❌ Need to map all 50+ parameters
- ❌ Requires Web MIDI API

---

## Recommended Implementation: Approach 1 (Cmajor Embedded View)

This is the cleanest and most direct approach for a Cmajor patch with UI.

### Step-by-Step Implementation

#### Step 1: Update main-vintage.js

Add Cmajor connection code at the top:

```javascript
let patchConnection = null;
let isStandalone = true;

// Initialize when DOM is ready
document.addEventListener('DOMContentLoaded', async () => {
    // Check if running in Cmajor player
    if (typeof window.cmajor !== 'undefined') {
        isStandalone = false;
        await initializeCmajorConnection();
    } else {
        console.log('Running in standalone mode (demo only)');
    }
    
    // Initialize UI components
    initializeKnobs();
    initializeToggles();
    initializeAnimations();
});

async function initializeCmajorConnection() {
    try {
        console.log('Connecting to Cmajor patch...');
        
        // Create patch connection
        patchConnection = await window.cmajor.createPatchConnection();
        
        // Get available parameters
        const params = await patchConnection.getParameters();
        console.log('Connected! Available parameters:', params.length);
        
        // Listen for parameter changes from patch
        patchConnection.addParameterListener((paramID, value) => {
            updateUIFromParameter(paramID, value);
        });
        
        // Listen for status changes
        patchConnection.addStatusListener((status) => {
            console.log('Patch status:', status);
        });
        
        console.log('Cmajor connection established');
        
    } catch (error) {
        console.error('Failed to connect to Cmajor:', error);
        isStandalone = true;
    }
}

function updateUIFromParameter(paramID, value) {
    // Find knob with matching parameter
    const knob = knobs.find(k => k.param === paramID);
    if (knob) {
        knob.value = value;
        knob.updateRotation();
        knob.updateNixieDisplay();
    }
}
```

#### Step 2: Update Knob.sendToEngine()

```javascript
sendToEngine() {
    if (patchConnection) {
        try {
            // Send parameter value to Cmajor patch
            patchConnection.sendParameterValue(this.param, this.value);
        } catch (error) {
            console.error(`Failed to send ${this.param}:`, error);
        }
    } else if (!isStandalone) {
        console.warn('Patch connection not ready');
    }
    // In standalone mode, just update UI (no error)
}
```

#### Step 3: Update Toggle Buttons

```javascript
class ToggleButton {
    // ... existing code ...
    
    sendToEngine() {
        if (patchConnection) {
            try {
                patchConnection.sendParameterValue(this.param, this.isOn ? 1.0 : 0.0);
            } catch (error) {
                console.error(`Failed to send ${this.param}:`, error);
            }
        }
    }
}
```

#### Step 4: Add Preset Loading

```javascript
async function loadPreset(presetPath) {
    try {
        const response = await fetch(presetPath);
        const preset = await response.json();
        
        // Apply all parameter values
        for (const [param, value] of Object.entries(preset)) {
            if (patchConnection) {
                await patchConnection.sendParameterValue(param, value);
            }
            
            // Update UI
            const knob = knobs.find(k => k.param === param);
            if (knob) {
                knob.setValue(value);
            }
        }
        
        console.log('Preset loaded:', presetPath);
        
    } catch (error) {
        console.error('Failed to load preset:', error);
    }
}
```

#### Step 5: Test the Connection

1. Close any running `cmaj play` instances
2. Run: `cmaj play CINTA.cmajorpatch`
3. UI should load with connection
4. Check browser console for: "Cmajor connection established"
5. Turn knobs and verify parameters change
6. Play MIDI notes and verify sound changes

---

## Testing Checklist

### Connection Tests
- [ ] UI loads in Cmajor player window
- [ ] Console shows "Connected! Available parameters: X"
- [ ] No connection errors in console

### Parameter Control Tests
- [ ] Vibe knob changes sound
- [ ] Warmth knob changes sound
- [ ] FM engine parameters work
- [ ] Tape engine parameters work
- [ ] Analog engine parameters work
- [ ] Engine ON/OFF toggles work
- [ ] Master volume works

### Preset Tests
- [ ] Preset browser shows all presets
- [ ] Loading preset updates UI
- [ ] Loading preset changes sound
- [ ] All 100 presets load correctly

### UI Tests
- [ ] Size modes work (Ctrl+1/2/3/4)
- [ ] VU meter animates with audio
- [ ] Tape reels spin
- [ ] Nixie displays update
- [ ] All knobs rotate smoothly

---

## Troubleshooting

### "patchConnection is null"
- Check if `window.cmajor` exists
- Verify CINTA.cmajorpatch has correct view config
- Make sure running via `cmaj play`, not browser

### "Parameter not found"
- Check parameter names match CINTA.cmajor exactly
- Verify parameter is defined in processor
- Check for typos in parameter names

### "UI doesn't update when playing"
- Add parameter listeners
- Implement updateUIFromParameter()
- Check console for listener errors

### "Knobs don't control sound"
- Verify sendParameterValue() is called
- Check parameter value ranges
- Test with simple parameter (master_volume)

---

## Next Steps

1. ✅ Update main-vintage.js with Cmajor connection code
2. ✅ Test connection in Cmajor player
3. ✅ Verify parameter control works
4. ✅ Test all 100 presets
5. ✅ Document any issues
6. ✅ Commit working UI-backend integration

---

## Expected Result

When complete, you'll have:
- ✅ Fully functional CINTA synthesizer
- ✅ Beautiful vintage UI controlling the synth
- ✅ All parameters working in real-time
- ✅ Preset loading functional
- ✅ Complete audio-visual experience

**CINTA will be a complete, professional synthesizer!** 🎛️🎹✨
