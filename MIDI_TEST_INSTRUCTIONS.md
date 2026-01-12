# CINTA MIDI Not Working - Diagnosis

## Problem
The Cmajor player is not receiving MIDI input from your keyboard.

## Evidence
From the console output:
```
Opening MIDI output: DONNER N32 1
```

Notice it says "MIDI **output**" not "MIDI **input**". The player is sending MIDI TO your keyboard, not receiving FROM it.

## Root Cause
The Cmajor player needs to be configured to open MIDI input devices. By default, it may not automatically open all available MIDI inputs.

## Solutions

### Solution 1: Use Computer Keyboard for Testing
The Cmajor player has a built-in computer keyboard to MIDI feature:
1. Click on the Cmajor player window to focus it
2. Use your computer keyboard keys to play notes:
   - A, S, D, F, G, H, J, K = white keys (C, D, E, F, G, A, B, C)
   - W, E, T, Y, U = black keys
   - Z, X = octave down/up

### Solution 2: Check MIDI Input Settings
The Cmajor player should have a settings or preferences menu:
1. Look for a gear icon or Settings menu
2. Find MIDI Input settings
3. Enable "DONNER N32" as an input device
4. Make sure it's set to receive, not just send

### Solution 3: Command Line MIDI Input
Try running with explicit MIDI input specification:
```powershell
cmaj play CINTA_Test.cmajorpatch --midi-in "DONNER N32"
```

### Solution 4: Use Virtual MIDI Cable
If the Cmajor player can't receive from hardware MIDI:
1. Install loopMIDI or similar virtual MIDI cable
2. Route your keyboard through the virtual cable
3. Have Cmajor listen to the virtual cable

## Immediate Test
**Try using your computer keyboard right now:**
1. Make sure the Cmajor "CINTA Test" window is focused (click on it)
2. Press the 'A' key on your computer keyboard
3. You should hear a beep sound

If this works, the synth is fine - it's just a MIDI routing issue.

## Next Steps
1. Test with computer keyboard first
2. If that works, we know the synth is working
3. Then we'll fix the MIDI keyboard routing
4. After MIDI works, we'll fix the knob pointer drift in the UI
