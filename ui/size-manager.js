/* ═══════════════════════════════════════════════════════════════
   CINTA UI SIZE MANAGER
   Handles 4 size modes with keyboard shortcuts and localStorage
   ═══════════════════════════════════════════════════════════════ */

class SizeManager {
    constructor() {
        this.container = document.querySelector('.synth-container');
        this.toggleBtn = document.getElementById('sizeToggleBtn');
        this.dropdown = document.getElementById('sizeDropdown');
        this.sizeLabel = document.getElementById('currentSizeLabel');
        this.indicator = document.getElementById('sizeIndicator');
        this.sizeOptions = document.querySelectorAll('.size-option');
        
        this.currentSize = 'full';
        this.sizes = {
            full: { label: 'FULL', width: 1400, height: 850 },
            compact: { label: 'COMPACT', width: 900, height: 500 },
            mini: { label: 'MINI', width: 500, height: 300 },
            strip: { label: 'STRIP', width: 300, height: 150 }
        };
        
        this.init();
    }
    
    init() {
        // Load saved size preference from localStorage
        const savedSize = localStorage.getItem('cinta-ui-size');
        if (savedSize && this.sizes[savedSize]) {
            this.setSize(savedSize, false);
        }
        
        // Toggle button click
        this.toggleBtn.addEventListener('click', (e) => {
            e.stopPropagation();
            this.toggleDropdown();
        });
        
        // Size option clicks
        this.sizeOptions.forEach(option => {
            option.addEventListener('click', () => {
                const size = option.dataset.size;
                this.setSize(size);
                this.closeDropdown();
            });
        });
        
        // Close dropdown when clicking outside
        document.addEventListener('click', (e) => {
            if (!this.dropdown.contains(e.target) && e.target !== this.toggleBtn) {
                this.closeDropdown();
            }
        });
        
        // Keyboard shortcuts: Ctrl+1/2/3/4
        document.addEventListener('keydown', (e) => {
            if (e.ctrlKey && !e.shiftKey && !e.altKey) {
                switch(e.key) {
                    case '1':
                        e.preventDefault();
                        this.setSize('full');
                        break;
                    case '2':
                        e.preventDefault();
                        this.setSize('compact');
                        break;
                    case '3':
                        e.preventDefault();
                        this.setSize('mini');
                        break;
                    case '4':
                        e.preventDefault();
                        this.setSize('strip');
                        break;
                }
            }
        });
        
        // Update active state in dropdown
        this.updateActiveOption();
    }
    
    setSize(size, showIndicator = true) {
        if (!this.sizes[size] || size === this.currentSize) return;
        
        // Remove all size classes
        Object.keys(this.sizes).forEach(s => {
            this.container.classList.remove(`size-${s}`);
        });
        
        // Add new size class
        this.container.classList.add(`size-${size}`);
        this.currentSize = size;
        
        // Update label
        this.sizeLabel.textContent = this.sizes[size].label;
        
        // Save to localStorage
        localStorage.setItem('cinta-ui-size', size);
        
        // Update active option in dropdown
        this.updateActiveOption();
        
        // Show size change indicator
        if (showIndicator) {
            this.showSizeIndicator(size);
        }
        
        // Dispatch custom event for other components
        window.dispatchEvent(new CustomEvent('cinta-size-changed', { 
            detail: { size, dimensions: this.sizes[size] }
        }));
    }
    
    toggleDropdown() {
        this.dropdown.classList.toggle('active');
    }
    
    closeDropdown() {
        this.dropdown.classList.remove('active');
    }
    
    updateActiveOption() {
        this.sizeOptions.forEach(option => {
            if (option.dataset.size === this.currentSize) {
                option.classList.add('active');
            } else {
                option.classList.remove('active');
            }
        });
    }
    
    showSizeIndicator(size) {
        const sizeInfo = this.sizes[size];
        this.indicator.textContent = `${sizeInfo.label} (${sizeInfo.width}×${sizeInfo.height})`;
        this.indicator.classList.add('show');
        
        setTimeout(() => {
            this.indicator.classList.remove('show');
        }, 1500);
    }
    
    // Public API
    getCurrentSize() {
        return this.currentSize;
    }
    
    getSizeInfo(size) {
        return this.sizes[size || this.currentSize];
    }
    
    cycleSize() {
        const sizeKeys = Object.keys(this.sizes);
        const currentIndex = sizeKeys.indexOf(this.currentSize);
        const nextIndex = (currentIndex + 1) % sizeKeys.length;
        this.setSize(sizeKeys[nextIndex]);
    }
}

// Initialize size manager when DOM is ready
let sizeManager = null;

document.addEventListener('DOMContentLoaded', () => {
    sizeManager = new SizeManager();
    
    // Make it globally accessible for debugging
    window.cintaSizeManager = sizeManager;
    
    console.log('CINTA Size Manager initialized');
    console.log('Keyboard shortcuts: Ctrl+1 (FULL), Ctrl+2 (COMPACT), Ctrl+3 (MINI), Ctrl+4 (STRIP)');
});

// Export for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = SizeManager;
}
