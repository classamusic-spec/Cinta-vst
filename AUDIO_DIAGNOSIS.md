# CINTA Audio Output Issue - Diagnosis

## Problem
No sound from CINTA synth with either:
- MIDI keyboard input
- Computer keyboard input

## What We Know
From the console output, Cmajor is opening:
```
Audio API: WASAPI
Output device: Speakers (Realtek(R) Audio)
Rate: 44100Hz
Block size: 128 frames
Output channels: 2
```

This means Cmajor is trying to send audio to "Speakers (Realtek(R) Audio)"

## Possible Issues

### 1. Wrong Audio Device Selected
The Cmajor player is sending audio to "Speakers (Realtek(R) Audio)" but you might be listening on a different device (like your MBOX Studio).

**Solution:** We need to tell Cmajor to use the MBOX Studio instead.

### 2. Audio Device Not Active
The Realtek speakers might not be the active output device in Windows.

**Check:**
- Right-click the speaker icon in Windows taskbar
- Click "Open Sound settings"
- Check which device is set as default output
- Make sure it's not muted

### 3. WASAPI Exclusive Mode
WASAPI might be in exclusive mode and blocked by another application.

**Check:**
- Close any other audio applications (DAWs, browsers with audio, etc.)
- Try again

## Solution: Force MBOX Studio Output

Let's restart Cmajor with the MBOX Studio as the audio output device.
