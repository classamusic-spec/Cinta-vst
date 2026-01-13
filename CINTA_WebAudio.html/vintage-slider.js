// CINTA Vintage Slider Component
// Ultra-detailed brass/gold theme with nixie tube displays

class VintageSlider {
    constructor(config) {
        this.container = config.container;
        this.param = config.param;
        this.label = config.label;
        this.min = config.min || 0;
        this.max = config.max || 100;
        this.value = config.value || 0;
        this.unit = config.unit || '';
        this.color = config.color || 'gold';
        this.decimals = config.decimals || 0;
        this.onChange = config.onChange || (() => {});
        
        this.isDragging = false;
        this.startY = 0;
        this.startValue = 0;
        
        this.render();
        this.attachEventListeners();
    }
    
    render() {
        const sliderHTML = `
            <div class="vintage-slider-container" data-param="${this.param}">
                <div class="nixie-display">
                    <span class="nixie-number">${this.formatValue(this.value)}</span>
                    ${this.unit ? `<span class="nixie-unit">${this.unit}</span>` : ''}
                </div>
                <div class="slider-track-container">
                    <div class="slider-track">
                        <div class="slider-fill" style="height: ${this.getPercentage()}%"></div>
                    </div>
                    <div class="slider-cap ${this.color}" style="top: ${100 - this.getPercentage()}%"></div>
                </div>
                <div class="slider-label">${this.label}</div>
            </div>
        `;
        
        this.container.innerHTML = sliderHTML;
        this.sliderContainer = this.container.querySelector('.vintage-slider-container');
        this.nixieNumber = this.container.querySelector('.nixie-number');
        this.sliderCap = this.container.querySelector('.slider-cap');
        this.sliderFill = this.container.querySelector('.slider-fill');
        this.trackContainer = this.container.querySelector('.slider-track-container');
    }
    
    formatValue(value) {
        if (this.decimals === 0) {
            return Math.round(value).toString().padStart(2, '0');
        }
        return value.toFixed(this.decimals);
    }
    
    getPercentage() {
        return ((this.value - this.min) / (this.max - this.min)) * 100;
    }
    
    setValue(newValue) {
        this.value = Math.max(this.min, Math.min(this.max, newValue));
        const percentage = this.getPercentage();
        
        this.nixieNumber.textContent = this.formatValue(this.value);
        this.sliderCap.style.top = `${100 - percentage}%`;
        this.sliderFill.style.height = `${percentage}%`;
        
        this.onChange(this.value);
    }
    
    attachEventListeners() {
        // Mouse events
        this.sliderCap.addEventListener('mousedown', (e) => this.startDrag(e));
        document.addEventListener('mousemove', (e) => this.onDrag(e));
        document.addEventListener('mouseup', () => this.stopDrag());
        
        // Touch events
        this.sliderCap.addEventListener('touchstart', (e) => this.startDrag(e.touches[0]));
        document.addEventListener('touchmove', (e) => this.onDrag(e.touches[0]));
        document.addEventListener('touchend', () => this.stopDrag());
        
        // Click on track to jump
        this.trackContainer.addEventListener('click', (e) => {
            if (e.target !== this.sliderCap) {
                const rect = this.trackContainer.getBoundingClientRect();
                const y = e.clientY - rect.top;
                const percentage = 100 - (y / rect.height * 100);
                const newValue = this.min + (percentage / 100) * (this.max - this.min);
                this.setValue(newValue);
            }
        });
    }
    
    startDrag(e) {
        this.isDragging = true;
        this.startY = e.clientY;
        this.startValue = this.value;
        this.sliderCap.style.cursor = 'grabbing';
    }
    
    onDrag(e) {
        if (!this.isDragging) return;
        
        const rect = this.trackContainer.getBoundingClientRect();
        const deltaY = this.startY - e.clientY;
        const deltaPercentage = (deltaY / rect.height) * 100;
        const deltaValue = (deltaPercentage / 100) * (this.max - this.min);
        
        this.setValue(this.startValue + deltaValue);
    }
    
    stopDrag() {
        if (this.isDragging) {
            this.isDragging = false;
            this.sliderCap.style.cursor = 'grab';
        }
    }
    
    // Public method to update value from external source
    updateValue(newValue) {
        this.setValue(newValue);
    }
}

// Helper function to create multiple sliders
function createSliderGroup(container, sliders, patchConnection) {
    const groupHTML = '<div class="slider-group"></div>';
    container.innerHTML = groupHTML;
    const group = container.querySelector('.slider-group');
    
    const sliderInstances = [];
    
    sliders.forEach(config => {
        const sliderContainer = document.createElement('div');
        group.appendChild(sliderContainer);
        
        const slider = new VintageSlider({
            container: sliderContainer,
            param: config.param,
            label: config.label,
            min: config.min,
            max: config.max,
            value: config.value,
            unit: config.unit,
            color: config.color,
            decimals: config.decimals,
            onChange: (value) => {
                if (patchConnection) {
                    patchConnection.sendEventOrValue(config.param, value);
                    console.log(`${config.param}: ${value}`);
                }
            }
        });
        
        sliderInstances.push(slider);
    });
    
    return sliderInstances;
}

// Export for use in main application
if (typeof window !== 'undefined') {
    window.VintageSlider = VintageSlider;
    window.createSliderGroup = createSliderGroup;
}
