# Cinta VST - Cmajor Project

This workspace is set up for developing VST plugins using Cmajor.

## Installing Cmajor

### Option 1: VSCode Extension (Recommended)
1. Open VSCode
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "Cmajor"
4. Install the "Cmajor Tools" extension by Cmajor Software
5. The extension will automatically install all required tools

### Option 2: Manual Installation
1. Visit [Cmajor Releases](https://github.com/cmajor-lang/cmajor/releases/latest)
2. Download `cmajor-windows-<version>.zip`
3. Extract to a folder (e.g., `C:\cmajor`)
4. Add the folder to your PATH or use the full path to `cmaj.exe`

## What You Get

- **cmaj.exe** - Command-line compiler and tools
- **CmajPerformer.dll** - Runtime library for embedding Cmajor
- **VST/AU plugins** - For loading Cmajor patches in DAWs

## Quick Start

### Create a New Patch
```bash
cmaj create MyPatch
```

### Run a Patch
```bash
cmaj play MyPatch.cmajorpatch
```

### Export as Plugin
```bash
# JUCE plugin
cmaj generate --target=juce --output=./MyPlugin MyPatch.cmajorpatch

# CLAP plugin
cmaj generate --target=clap --output=./MyPlugin MyPatch.cmajorpatch

# Web Audio
cmaj generate --target=webaudio-html --output=./web MyPatch.cmajorpatch
```

## Resources

- [Cmajor Language Guide](https://github.com/cmajor-lang/cmajor/blob/main/docs/Cmaj%20Language%20Guide.md)
- [Quick Start Guide](https://github.com/cmajor-lang/cmajor/blob/main/docs/Cmaj%20Quick%20Start.md)
- [Example Patches](https://github.com/cmajor-lang/cmajor/tree/main/examples/patches)
- [Official Website](https://cmajor.dev)

## Next Steps

1. Install Cmajor using one of the methods above
2. Create your first patch with `cmaj create` or through VSCode
3. Start coding your VST plugin in Cmajor!
