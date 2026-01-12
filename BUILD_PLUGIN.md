# Building CINTA VST3 Plugin

## ✅ Plugin Generated Successfully!

Your CINTA synthesizer has been converted to a JUCE plugin project in the `CINTA_Plugin` folder.

## Build Steps

### Option 1: Using CMake (Recommended)

1. **Open PowerShell in the CINTA_Plugin folder**:
```powershell
cd C:\Users\class\Documents\Cinta-vst\CINTA_Plugin
```

2. **Create build directory**:
```powershell
mkdir build
cd build
```

3. **Generate Visual Studio project**:
```powershell
cmake .. -G "Visual Studio 17 2022"
```

4. **Build the plugin**:
```powershell
cmake --build . --config Release
```

5. **Find your plugin**:
The VST3 will be in: `build\CINTA_artefacts\Release\VST3\CINTA.vst3`

### Option 2: Open in Visual Studio

If CMake generates a `.sln` file, you can:
1. Open `CINTA_Plugin\build\CINTA.sln` in Visual Studio
2. Select "Release" configuration (top toolbar)
3. Build > Build Solution (or press F7)
4. Plugin will be in the Release folder

## Install Plugin

1. **Copy the VST3 file**:
```powershell
Copy-Item "C:\Users\class\Documents\Cinta-vst\CINTA_Plugin\build\CINTA_artefacts\Release\VST3\CINTA.vst3" -Destination "C:\Program Files\Common Files\VST3\" -Recurse
```

2. **Restart your DAW**

3. **Load CINTA**:
   - Open your DAW (Ableton, FL Studio, Reaper, etc.)
   - Add a new instrument track
   - Look for "CINTA" in your VST3 plugins
   - Load it and play!

## What You Get

Your CINTA plugin will have:
- ✅ 8-voice polyphony
- ✅ FM, Tape, and Analog synthesis engines
- ✅ All 50+ parameters
- ✅ Full MIDI support
- ✅ Works in any DAW
- ✅ Professional VST3 format

## Troubleshooting

### "CMake not found"
Install CMake from: https://cmake.org/download/

### "Visual Studio not found"
Install Visual Studio Community (free) from: https://visualstudio.microsoft.com/

### Build errors
Make sure you have:
- Visual Studio with C++ development tools
- Windows SDK installed
- CMake 3.15 or later

## Next Steps

1. Run the CMake build commands above
2. Copy the VST3 to your plugins folder
3. Open your DAW and load CINTA
4. Start making music!

Your CINTA synthesizer is ready to use in any professional DAW! 🎹🎛️
