# 🗺️ FDF (Fil de Fer)

## 📍 Overview

**FDF** (Fil de Fer) is a project in the 42 Cursus that involves creating a 3D wireframe graphics renderer. It teaches graphics programming, mathematical projection, and working with graphics libraries.

## 🎯 Objectives

- Render 3D models in 2D using wireframe representation
- Implement mathematical projections (isometric, etc.)
- Work with graphics library (MLX)
- Handle keyboard input and real-time rendering
- Optimize drawing performance

## 🛠️ Features

- **3D Wireframe Rendering:**
  - Parse `.fdf` map files
  - Display 3D models as wireframe
  - Use isometric projection

- **Transformations:**
  - Zoom in/out
  - Rotate on X, Y, Z axes
  - Translate (pan)
  - Scale/stretch Z-axis

- **Visual Enhancements:**
  - Color gradients based on altitude
  - Smooth line drawing
  - Anti-aliasing (optional)

- **Interactive Features:**
  - Real-time keyboard controls
  - Smooth animations
  - Menu display with controls

## 📦 Project Structure

```
fdf/
├── Makefile
├── includes/
│   └── fdf.h              # Header file
├── sources/
│   ├── main.c             # Entry point
│   ├── read_map.c         # Parse .fdf files
│   ├── draw.c             # Drawing functions
│   ├── keys.c             # Keyboard handling
│   ├── set_param.c        # Transformation parameters
│   └── utils.c            # Utility functions
├── maps/                  # Sample .fdf map files
└── libs/                  # External libraries (MLX, libft, ft_printf)
```

## 🗺️ Map File Format

**.fdf files** contain a 2D grid of integers representing height values:

```
0  0  0  0  0
0  10 10 10 0
0  10 20 10 0
0  10 10 10 0
0  0  0  0  0
```

Optional color values (hexadecimal):

```
0,0xFF0000  0,0x00FF00  0,0x0000FF
10,0xFFFF00 20,0xFFFFFF 10,0xFF00FF
```

## 🚀 Compilation & Execution

```bash
make              # Compile the project
./fdf maps/42.fdf # Run with a map file
```

### Required Arguments

```bash
./fdf <map_file.fdf>
```

## ⌨️ Controls

- **Arrows** - Translate (move around)
- **+/-** - Zoom in/out
- **Numpad 4/6** - Rotate around X-axis
- **Numpad 2/8** - Rotate around Y-axis
- **Numpad 1/3** - Rotate around Z-axis
- **A/S** - Raise/lower Z-axis
- **R** - Reset view
- **ESC** - Close window

## 🎨 Included Maps

- `42.fdf` - The 42 logo
- `pyramide.fdf` - Pyramid structure
- `mars.fdf` - Mars terrain
- `julia.fdf` - Julia set fractal
- And more...

## 🛠️ Technical Details

- **Graphics Library:** MLX (MinilibX)
- **Projection:** Isometric
- **Color Model:** RGB with optional gradients
- **Line Algorithm:** Bresenham's line algorithm
- **Platform:** Linux (with X11)

## 📚 Learning Points

- 3D mathematics and projections
- Graphics library usage (MLX)
- File parsing
- Event-driven programming
- Matrix transformations
- Performance optimization

## 🔧 Compilation Details

```bash
make        # Build executable
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Clean and rebuild
```

## 📝 Notes

- Map files must be properly formatted
- Handles very large maps efficiently
- Smooth rendering even with thousands of points
- Error handling for invalid files
