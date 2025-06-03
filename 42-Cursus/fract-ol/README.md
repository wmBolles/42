# 🌀 Fract-ol

[![42 School](https://img.shields.io/badge/42_School-fract--ol-blue?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics](https://img.shields.io/badge/Graphics-MinilibX-green?style=for-the-badge)](https://github.com/42Paris/minilibx-linux)
[![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)](https://github.com/th3f/42-Cursus)

> *"Fractals are the thumbprints of nature."* - Benoit Mandelbrot

A beautiful fractal renderer that visualizes the mathematical beauty of the Mandelbrot and Julia sets using the MinilibX graphics library.

## 📋 Table of Contents

- [🎯 About](#-about)
- [✨ Features](#-features)
- [🧮 Mathematical Background](#-mathematical-background)
- [🚀 Installation](#-installation)
- [💻 Usage](#-usage)
- [🎮 Controls](#-controls)
- [🔧 Implementation](#-implementation)
- [📁 Project Structure](#-project-structure)
- [🧪 Testing](#-testing)
- [📚 Learning Objectives](#-learning-objectives)
- [📖 Resources](#-resources)

## 🎯 About

**Fract-ol** is a 42 School project that introduces students to computer graphics programming and mathematical visualization. The project focuses on rendering fractals using the MinilibX library, implementing complex mathematical algorithms, and creating an interactive graphical interface.

**Key Concepts:**
- Complex number mathematics
- Iterative algorithms
- Computer graphics and pixel manipulation
- Event handling and user interaction
- Performance optimization

## ✨ Features

### 🌟 Core Features
- **Mandelbrot Set Rendering**: Beautiful visualization of the famous Mandelbrot fractal
- **Julia Set Rendering**: Interactive Julia sets with customizable parameters
- **Real-time Zoom**: Smooth zooming capabilities with mouse wheel
- **Color Schemes**: Multiple color palettes for enhanced visualization
- **Mouse Navigation**: Click to center and zoom on specific areas

### 🎨 Visual Features
- **Smooth Gradients**: Beautiful color transitions based on iteration counts
- **High Resolution**: Support for detailed fractal exploration
- **Real-time Rendering**: Immediate visual feedback for all interactions
- **Infinite Zoom**: Explore fractals at incredible detail levels

### ⚡ Performance Features
- **Optimized Algorithms**: Efficient iteration and calculation methods
- **Memory Management**: Proper handling of graphics resources
- **Responsive Interface**: Smooth user interaction even at high zoom levels

## 🧮 Mathematical Background

### Mandelbrot Set
The Mandelbrot set is defined by the iterative formula:
```
z_{n+1} = z_n² + c
```
Where:
- `z₀ = 0`
- `c` is a complex number representing each pixel
- A point belongs to the set if the sequence remains bounded

### Julia Set
Julia sets use the same formula but with different initial conditions:
```
z_{n+1} = z_n² + c
```
Where:
- `z₀` varies (represents each pixel)
- `c` is a constant complex parameter
- Different values of `c` produce different Julia sets

### Convergence Testing
```c
int	iterate_mandelbrot(double real, double imag, int max_iter)
{
	double	z_real = 0.0;
	double	z_imag = 0.0;
	double	temp;
	int		i = 0;

	while (z_real * z_real + z_imag * z_imag <= 4.0 && i < max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}
```

## 🚀 Installation

### Prerequisites
- **GCC** or **Clang** compiler
- **Make** build system
- **MinilibX** graphics library
- **X11** development libraries (Linux)

### Clone and Build
```bash
# Clone the repository
git clone https://github.com/yourusername/42-Cursus.git
cd 42-Cursus/fract-ol

# Build the project
make

# Clean build files
make clean

# Remove all generated files
make fclean

# Rebuild everything
make re
```

## 💻 Usage

### Basic Usage
```bash
# Run Mandelbrot set
./fractol mandelbrot

# Run Julia set with default parameters
./fractol julia

# Run Julia set with custom parameters
./fractol julia -0.7 0.27015
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
```

### Example Commands
```bash
# Classic Mandelbrot
./fractol mandelbrot

# Beautiful Julia sets
./fractol julia -0.7 0.27015    # Spiral Julia
./fractol julia -0.8 0.156      # Lightning Julia
./fractol julia 0.285 0.01      # Douady Rabbit
./fractol julia -0.123 0.745    # Siegel Disk
```

## 🎮 Controls

### Mouse Controls
| Action | Description |
|--------|-------------|
| **Left Click** | Center view on clicked point |
| **Mouse Wheel Up** | Zoom in (2x) |
| **Mouse Wheel Down** | Zoom out (0.5x) |
| **Mouse Move** (Julia) | Change Julia parameters in real-time |

### Keyboard Controls
| Key | Action |
|-----|--------|
| **ESC** | Exit program |
| **R** | Reset view to default |
| **C** | Cycle color schemes |
| **+/-** | Increase/decrease iterations |
| **Arrow Keys** | Pan view |
| **Space** | Toggle between fractals |

## 🔧 Implementation

### Core Components

#### 1. Fractal Engine (`fractals/`)
```c
// Mandelbrot calculation
int mandelbrot_iterate(t_complex c, int max_iter);

// Julia calculation  
int julia_iterate(t_complex z, t_complex c, int max_iter);

// Color mapping
int get_color(int iterations, int max_iter, int color_scheme);
```

#### 2. Graphics Handler (`fract-ol.c`)
```c
// Window management
void init_fractal(t_fractal *fractal);
void render_fractal(t_fractal *fractal);
void handle_events(t_fractal *fractal);
```

#### 3. Complex Numbers (`tools/`)
```c
typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

t_complex complex_add(t_complex a, t_complex b);
t_complex complex_multiply(t_complex a, t_complex b);
double complex_magnitude_squared(t_complex z);
```

### Optimization Techniques
- **Early Bailout**: Stop iteration when magnitude exceeds escape radius
- **Smooth Coloring**: Use fractional iteration counts for gradient effects
- **Efficient Scaling**: Optimized coordinate transformation
- **Memory Pool**: Reuse allocated graphics buffers

## 📁 Project Structure

```
fract-ol/
├── Makefile              # Build configuration
├── fract-ol.c           # Main program entry
├── inc/
│   └── headers.h        # Header definitions
├── fractals/
│   ├── mandelbrot.c     # Mandelbrot implementation
│   └── julia.c          # Julia set implementation
├── tools/
│   ├── complex.c        # Complex number operations
│   ├── colors.c         # Color scheme functions
│   └── utils.c          # Utility functions
├── ft_printf/           # Custom printf implementation
└── images/              # Sample fractal images
```

## 🧪 Testing

### Manual Testing
```bash
# Test different fractals
./fractol mandelbrot
./fractol julia
./fractol julia -0.7 0.27015

# Test error handling
./fractol                    # Should show usage
./fractol invalid           # Should show error
./fractol julia abc def     # Should handle invalid numbers
```

### Visual Verification
1. **Zoom Test**: Verify zooming maintains fractal detail
2. **Color Test**: Check all color schemes display correctly
3. **Navigation Test**: Ensure smooth panning and centering
4. **Performance Test**: Monitor frame rate during intensive operations

### Memory Testing
```bash
# Check for memory leaks
valgrind --leak-check=full ./fractol mandelbrot

# Monitor resource usage
top -p $(pgrep fractol)
```

## 📚 Learning Objectives

After completing this project, you will understand:

### 🔢 Mathematical Concepts
- Complex number arithmetic and operations
- Iterative mathematical sequences
- Fractal geometry and self-similarity
- Numerical analysis and convergence testing

### 💻 Programming Skills
- Graphics programming with MinilibX
- Event-driven programming paradigms
- Performance optimization techniques
- Mathematical algorithm implementation

### 🎨 Graphics Programming
- Pixel manipulation and color mapping
- Coordinate system transformations
- Real-time rendering techniques
- User interface design principles

### 🏗️ Software Engineering
- Modular code organization
- Error handling and input validation
- Resource management and cleanup
- Cross-platform compatibility considerations

## 📖 Resources

### 📚 Fractal Mathematics
- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Complex Numbers](https://en.wikipedia.org/wiki/Complex_number)
- [Fractal Geometry](https://mathworld.wolfram.com/Fractal.html)

### 🔧 Technical Documentation
- [MinilibX Documentation](https://github.com/42Paris/minilibx-linux)
- [X11 Programming](https://tronche.com/gui/x/xlib/)
- [Computer Graphics Principles](https://learnopengl.com/)

### 🎨 Inspiration
- [Fractal Explorer](https://mathworld.wolfram.com/FractalExplorer.html)
- [Beautiful Fractals Gallery](https://fractalfoundation.org/resources/fractal-galleries/)
- [Interactive Mandelbrot](https://mandelbrot.site/)

---

<div align="center">

**Fract-ol** - Exploring the infinite beauty of mathematical fractals 🌀

*Made with ❤️ at 42 School*

</div>
