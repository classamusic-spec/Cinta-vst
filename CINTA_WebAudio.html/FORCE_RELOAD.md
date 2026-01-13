# CRITICAL: Browser Cache Issue

The Cmajor patch is being cached by the browser. To force a reload:

## Steps to Clear Cache and Reload:

1. **Hard Refresh**: Press `Ctrl + Shift + R` (or `Cmd + Shift + R` on Mac)

2. **Clear Browser Cache**:
   - Press `F12` to open DevTools
   - Right-click the refresh button
   - Select "Empty Cache and Hard Reload"

3. **Close and Reopen Browser Tab**:
   - Close the tab completely
   - Reopen `http://localhost:8080`

4. **Restart Web Server**:
   - Stop the server (Ctrl+C in terminal)
   - Restart: `python -m http.server 8080` or `npx http-server -p 8080`

5. **Clear Service Workers** (if any):
   - F12 → Application tab → Service Workers → Unregister

## Version Updated:
- Changed from `1.0.0` to `1.0.1` in both `.cmajorpatch` files
- This should force Cmajor to recompile the patch

## What Was Fixed:
- Release phase now uses simple linear decay: `voice_amp_level -= 1.0 / (release_time * sampleRate)`
- Voice recycling: `voice_active[v] = false` when release completes
- NoteOff properly sets `voice_active = false` and `phase = 3`

## If Still Sticking After Cache Clear:
The issue may be that the AudioWorklet is caching the compiled Cmajor code. Try:
1. Close ALL browser tabs
2. Restart the browser completely
3. Clear browser data (Settings → Privacy → Clear browsing data → Cached files)
4. Reopen the page
