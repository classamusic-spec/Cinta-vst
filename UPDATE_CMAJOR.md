# How to Update Cmajor Tools

## Current Version
- **Installed:** 1.0.3088 (Dec 19, 2025)
- **Latest:** 1.0.3096
- **Update Available:** Yes

## Method 1: Update VSCode Extension (Easiest)

1. Open VSCode
2. Press `Ctrl+Shift+X` to open Extensions
3. Search for "Cmajor"
4. Click "Update" next to the Cmajor Tools extension
5. Reload VSCode when prompted

## Method 2: Manual Download & Install

### Step 1: Download Latest Release

Visit: https://github.com/cmajor-lang/cmajor/releases/latest

Download the appropriate file for Windows:
- **cmajor-windows-x64.zip** (for 64-bit Windows)

### Step 2: Extract Files

1. Extract the downloaded ZIP file
2. You'll get a folder with `cmaj.exe` and other tools

### Step 3: Replace Old Version

**Option A: Replace in VSCode Extension Folder**
```powershell
# Backup current version
Copy-Item "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin" `
          "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin.backup" -Recurse

# Copy new cmaj.exe to extension folder
Copy-Item "path\to\extracted\cmaj.exe" `
          "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin\cmaj.exe" -Force
```

**Option B: Install to System Path**
```powershell
# Create Cmajor folder in Program Files
New-Item -Path "C:\Program Files\Cmajor" -ItemType Directory -Force

# Copy all files
Copy-Item "path\to\extracted\*" "C:\Program Files\Cmajor\" -Recurse -Force

# Add to PATH (run as Administrator)
[Environment]::SetEnvironmentVariable(
    "Path",
    [Environment]::GetEnvironmentVariable("Path", "Machine") + ";C:\Program Files\Cmajor",
    "Machine"
)
```

### Step 4: Verify Installation

```powershell
# Check version
& "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin\cmaj.exe" --version

# Or if installed to PATH
cmaj --version
```

## After Updating

### Test CINTA Compilation

Once updated, try compiling CINTA again:

```powershell
cd C:\Users\class\Documents\Cinta-vst

# Try compilation with new version
& "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin\cmaj.exe" play CINTA.cmajorpatch --dry-run
```

The `--dry-run` flag will build the patch and report errors without trying to play audio.

## What's New in 1.0.3096

The newer version may include:
- Bug fixes for internal compiler errors
- Improved type casting
- Better voice allocation handling
- LLVM backend improvements

## Troubleshooting

### If Update Doesn't Fix Compilation Error

If the internal compiler error persists after updating:

1. **Simplify Architecture** - Try reducing voice count or engines
2. **Report Bug** - File issue at https://github.com/cmajor-lang/cmajor/issues
3. **Alternative Approach** - Use single-engine architecture temporarily

### If VSCode Extension Won't Update

1. Uninstall the Cmajor extension completely
2. Restart VSCode
3. Reinstall from Extensions marketplace
4. This will get you the latest version

## Quick Commands Reference

```powershell
# Check current version
cmaj --version

# Test patch without playing
cmaj play CINTA.cmajorpatch --dry-run

# Build and show errors
cmaj play CINTA.cmajorpatch --stop-on-error

# Generate C++ code (alternative if JIT fails)
cmaj generate --target=cpp --output=CINTA.cpp CINTA.cmajorpatch
```

---

**Next Steps After Update:**
1. Verify new version is installed
2. Try compiling CINTA again
3. Check if internal compiler error is resolved
4. If still failing, consider simplifying architecture
