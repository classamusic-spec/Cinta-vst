# CINTA UI Size Modes Documentation

## Overview

CINTA now features a fully responsive UI with 4 size modes that can be toggled via button, dropdown menu, or keyboard shortcuts. Your size preference is automatically saved.

## 4 Size Modes

### 1. FULL (1050×640) - Everything Visible
**Keyboard:** `Ctrl+1`

Complete studio view with all features (75% scale for comfortable desktop use):
- ✅ All 3 synthesis engines (FM, Tape, Analog)
- ✅ Complete texture rack with all effects
- ✅ Envelope and LFO sections
- ✅ Full arpeggiator with pattern display
- ✅ VU meter and tape deck animations
- ✅ Preset browser
- ✅ Master section with all controls

**Best for:** Full production work, sound design, preset creation

### 2. COMPACT (900×500) - Engines + Macros + Arp ⭐ DEFAULT
**Keyboard:** `Ctrl+2`

**This is the default mode** - Streamlined view for daily use:
- ✅ 3 engine panels with on/off toggles
- ✅ Master macro controls (Vibe, Warmth, Space, Movement, Grit)
- ✅ Arpeggiator pattern display
- ✅ Essential controls only
- ❌ Detailed knobs hidden
- ❌ Texture rack hidden
- ❌ Envelope/LFO sections hidden

**Best for:** Live performance, quick tweaking, limited screen space

### 3. MINI (500×300) - Macros + Engine Toggles + Master
**Keyboard:** `Ctrl+3`

Minimal control surface:
- ✅ Engine on/off toggles (FM, Tape, Analog)
- ✅ Master macro knobs
- ✅ Master volume control
- ❌ Pattern displays hidden
- ❌ All detailed controls hidden
- ❌ VU meter and tape deck hidden

**Best for:** Quick adjustments, monitoring, small displays

### 4. STRIP (300×150) - Vibe + Master + Arp + VU Meter
**Keyboard:** `Ctrl+4`

Ultra-minimal strip:
- ✅ Vibe macro knob
- ✅ Master volume
- ✅ Arpeggiator on/off toggle
- ✅ VU meter (scaled down)
- ✅ CINTA badge
- ❌ Everything else hidden

**Best for:** DAW integration, minimal footprint, essential controls with visual feedback

## How to Use

### Toggle Button
1. Click the **size toggle button** in the top-right corner
2. Shows current size mode (FULL, COMPACT, MINI, or STRIP)
3. Click to open dropdown menu with all 4 options

### Dropdown Menu
- Displays all 4 size modes with dimensions
- Shows keyboard shortcuts for each mode
- Current mode is highlighted in gold
- Click any option to switch instantly

### Keyboard Shortcuts
- **Ctrl+1** → FULL mode (1400×850)
- **Ctrl+2** → COMPACT mode (900×500)
- **Ctrl+3** → MINI mode (500×300)
- **Ctrl+4** → STRIP mode (300×150)

### Size Change Indicator
When switching modes, a temporary indicator appears showing:
- Mode name (e.g., "COMPACT")
- Dimensions (e.g., "900×500")
- Fades out after 1.5 seconds

## Automatic Saving

Your size preference is automatically saved to browser localStorage:
- Saved immediately when you change size
- Restored automatically when you reload the page
- Persists across browser sessions
- Storage key: `cinta-ui-size`

## Smooth Transitions

All size changes feature smooth animations:
- **0.4s** container resize with cubic-bezier easing
- **0.3s** fade in/out for hidden elements
- Maintains vintage aesthetic throughout transitions
- No jarring jumps or layout shifts

## Technical Details

### Files Added/Modified

**New Files:**
- `ui/size-modes.css` - Complete CSS for all 4 modes
- `ui/size-manager.js` - JavaScript size management system

**Modified Files:**
- `ui/index-vintage.html` - Added size toggle UI and scripts
- `ui/styles-vintage.css` - Added transitions and overflow handling

### CSS Classes

```css
.synth-container.size-full    /* 1400×850 - Everything */
.synth-container.size-compact /* 900×500 - Streamlined */
.synth-container.size-mini    /* 500×300 - Minimal */
.synth-container.size-strip   /* 300×150 - Ultra-minimal */
```

### JavaScript API

```javascript
// Access the size manager
window.cintaSizeManager

// Get current size
cintaSizeManager.getCurrentSize() // Returns: 'full', 'compact', 'mini', or 'strip'

// Set size programmatically
cintaSizeManager.setSize('compact')

// Get size info
cintaSizeManager.getSizeInfo('full')
// Returns: { label: 'FULL', width: 1400, height: 850 }

// Cycle through sizes
cintaSizeManager.cycleSize()
```

### Custom Events

Listen for size changes:
```javascript
window.addEventListener('cinta-size-changed', (e) => {
    console.log('New size:', e.detail.size);
    console.log('Dimensions:', e.detail.dimensions);
});
```

## Use Cases

### Studio Production (FULL)
- Complete access to all parameters
- Sound design and preset creation
- Full visual feedback with VU meters and animations

### Live Performance (COMPACT)
- Quick engine switching
- Macro control for expressive performance
- Pattern visualization for timing

### DAW Integration (MINI/STRIP)
- Minimal screen real estate
- Essential controls only
- Focus on music, not UI

### Mobile/Tablet (COMPACT/MINI)
- Optimized for smaller screens
- Touch-friendly larger controls
- Responsive layout

## Responsive Behavior

The UI automatically adapts:
- Scales knobs and controls proportionally
- Hides non-essential elements
- Maintains vintage aesthetic at all sizes
- Smooth transitions between modes

## Browser Compatibility

- ✅ Chrome/Edge (Chromium)
- ✅ Firefox
- ✅ Safari
- ✅ Opera
- Requires: localStorage, CSS transitions, flexbox/grid

## Tips & Tricks

1. **Quick Access:** Memorize keyboard shortcuts for instant switching
2. **Workflow:** Start in FULL, switch to COMPACT for performance
3. **Screen Space:** Use STRIP mode when working in a DAW
4. **Customization:** Size preference saves automatically
5. **Visual Feedback:** Watch the size indicator for confirmation

## Future Enhancements

Potential additions:
- Custom size presets
- Drag-to-resize functionality
- Per-section collapse/expand
- Saved layouts per project
- MIDI learn for size switching

---

**Your CINTA UI now adapts to any workflow!** 🎛️

Press `Ctrl+1/2/3/4` to try all 4 modes instantly.
