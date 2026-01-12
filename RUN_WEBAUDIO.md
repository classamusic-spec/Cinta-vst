# Running CINTA WebAudio Version

## The Problem
Opening `index.html` directly from the file system causes CORS errors because browsers block JavaScript modules loaded from `file://` URLs.

## Solution: Use a Local Web Server

### Option 1: PowerShell HTTP Server (Simplest)

Run this command in PowerShell:

```powershell
cd C:\Users\class\Documents\Cinta-vst\CINTA_WebAudio.html
python -m http.server 8080
```

Then open: http://localhost:8080

**If Python not installed**, use this PowerShell script:

```powershell
cd C:\Users\class\Documents\Cinta-vst
npx http-server CINTA_WebAudio.html -p 8080
```

### Option 2: Use Node.js http-server (If you have Node.js)

```powershell
npm install -g http-server
cd C:\Users\class\Documents\Cinta-vst\CINTA_WebAudio.html
http-server -p 8080
```

Then open: http://localhost:8080

### Option 3: Use VS Code Live Server Extension

1. Install "Live Server" extension in VS Code
2. Right-click on `CINTA_WebAudio.html/index.html`
3. Select "Open with Live Server"
4. CINTA opens in browser automatically

### Option 4: Upload to GitHub Pages (Public Access)

Since your code is on GitHub, you can enable GitHub Pages:

1. Go to: https://github.com/classamusic-spec/Cinta-vst/settings/pages
2. Under "Source", select "main" branch
3. Select folder: `/CINTA_WebAudio.html`
4. Click "Save"
5. Your CINTA will be live at: `https://classamusic-spec.github.io/Cinta-vst/`

## Easiest Method Right Now

Since you have VS Code open, the **Live Server extension** is the quickest:

1. Open VS Code Extensions (Ctrl+Shift+X)
2. Search for "Live Server"
3. Install it
4. Right-click `CINTA_WebAudio.html/index.html`
5. Click "Open with Live Server"

CINTA will open in your browser with no CORS errors!

## What You'll Get

Once running via HTTP:
- ✅ Full CINTA synthesizer in browser
- ✅ MIDI keyboard support (browser will ask permission)
- ✅ Computer keyboard support (A S D F G keys)
- ✅ All synthesis parameters
- ✅ No installation needed

## Current Server Running

A PowerShell HTTP server is attempting to start on http://localhost:8080

Open that URL in your browser to use CINTA!
