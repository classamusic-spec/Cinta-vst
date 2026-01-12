# Installing C++ Compiler Tools - Step by Step

## Visual Studio Installer Should Be Opening Now

I've launched the Visual Studio Installer for you. Follow these steps:

## Step-by-Step Instructions

### 1. In Visual Studio Installer Window

You should see a window showing "Visual Studio Build Tools 2022"

### 2. Click "Modify"

- Find "Visual Studio Build Tools 2022" in the list
- Click the **"Modify"** button next to it

### 3. Select C++ Workload

In the Workloads tab:
- ✅ Check **"Desktop development with C++"**
- This will automatically select required components

### 4. Verify Individual Components (Optional)

Click the "Individual components" tab and make sure these are checked:
- ✅ MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
- ✅ Windows 10 SDK or Windows 11 SDK
- ✅ C++ CMake tools for Windows

### 5. Install

- Click the **"Modify"** button at the bottom right
- Download size: ~2-3 GB
- Installation time: 10-20 minutes depending on your internet speed

### 6. Wait for Installation

The installer will:
- Download required files
- Install C++ compiler
- Install build tools
- Configure environment

**Do NOT close the installer until it says "Installation succeeded"**

## After Installation Complete

Once you see "Installation succeeded":

### 1. Close Visual Studio Installer

### 2. Open a NEW PowerShell window
(Important: Must be a new window to pick up environment changes)

### 3. Run these commands:

```powershell
cd C:\Users\class\Documents\Cinta-vst\CINTA_Plugin\build

# Clear old cache
Remove-Item CMakeCache.txt -ErrorAction SilentlyContinue
Remove-Item CMakeFiles -Recurse -ErrorAction SilentlyContinue

# Generate Visual Studio project
cmake .. -G "Visual Studio 17 2022"

# Build CINTA VST3 (this takes 2-5 minutes)
cmake --build . --config Release
```

### 4. Wait for Build

You'll see lots of compilation messages. When it's done, you'll see:
```
Build succeeded.
```

### 5. Find Your VST3

Your plugin will be at:
```
C:\Users\class\Documents\Cinta-vst\CINTA_Plugin\build\CINTA_artefacts\Release\VST3\CINTA.vst3
```

### 6. Install VST3

Copy to your VST3 folder:
```powershell
Copy-Item "C:\Users\class\Documents\Cinta-vst\CINTA_Plugin\build\CINTA_artefacts\Release\VST3\CINTA.vst3" -Destination "C:\Program Files\Common Files\VST3\" -Recurse -Force
```

### 7. Use in DAW

- Restart your DAW (Ableton, FL Studio, Reaper, etc.)
- CINTA will appear in your VST3 plugins
- Load it and start making music!

## Troubleshooting

**If Visual Studio Installer doesn't open:**
- Press Windows key
- Type "Visual Studio Installer"
- Click to open it manually

**If you don't see "Build Tools 2022":**
- You might need to install Visual Studio Community 2022 instead
- Download from: https://visualstudio.microsoft.com/downloads/

**If CMake still can't find Visual Studio after installation:**
- Make sure you opened a NEW PowerShell window
- Try restarting your computer

## Current Status

✅ CINTA synthesizer complete (8-voice, 3 engines, 100 presets)
✅ JUCE plugin project generated
✅ CMake installed
⏳ Installing C++ compiler tools...
⏳ Ready to build VST3 after installation

**Let me know when the installation completes and I'll help you build the VST3!**
