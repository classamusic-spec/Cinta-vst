# CINTA Quick Start Guide

## ✅ What's Working Now

The Cmajor server is running and serving your CINTA WebAudio version!

## 🌐 Open CINTA in Browser

**Option 1: Direct URL**
```
http://127.0.0.1:51000
```

**Option 2: Session URL**
```
http://127.0.0.1:51000/session_78f3e4aed/cmaj-patch-chooser.html
```

Just paste either URL into your browser.

## 🎹 How to Use CINTA WebAudio

1. **Load the Patch:**
   - You'll see a patch chooser
   - Select "CINTA" from the list
   - Click to load it

2. **Play with Computer Keyboard:**
   - A, S, D, F, G, H, J, K = notes
   - W, E, T, Y, U = black keys
   - Z, X = octave down/up

3. **Connect MIDI Keyboard:**
   - Browser will ask for MIDI permission
   - Allow access
   - Your DONNER N32 will work

4. **Adjust Parameters:**
   - All CINTA synthesis parameters available
   - FM, Tape, and Analog engine controls
   - Real-time parameter changes

## 🔄 Restart Server (if needed)

If the server stops, run:
```powershell
cd C:\Users\class\Documents\Cinta-vst
cmaj server CINTA_WebAudio.html
```

Then open: http://127.0.0.1:51000

## 📦 For VST3 Plugin

To build the VST3 plugin (requires Visual Studio 2022):

1. Install Visual Studio 2022 Community (free)
2. Select "Desktop development with C++"
3. Run:
```powershell
cd C:\Users\class\Documents\Cinta-vst\CINTA_Plugin\build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
```

## 🎛️ Current Status

✅ CINTA synthesizer code complete
✅ WebAudio version running on http://127.0.0.1:51000
✅ Cmajor server active
✅ Ready to play!

**Just open the URL in your browser and start making music!** 🎹✨
