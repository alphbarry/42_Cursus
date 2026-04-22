# 🎨 MiniRT

## 📍 Overview

**MiniRT** is a project in the 42 Cursus that involves creating a basic ray tracing renderer. It teaches 3D graphics programming, ray tracing algorithms, and graphic rendering fundamentals.

## 🎯 Objectives

- Implement a ray tracing algorithm from scratch
- Render 3D scenes with lighting and shadows
- Work with geometric transformations
- Handle materials and colors
- Optimize rendering performance

## 🛠️ Features

- **Ray Tracing Rendering:**
  - Trace rays from camera through pixels
  - Calculate intersections with objects
  - Implement Phong lighting model
  - Support for shadows and reflections

- **Supported Objects:**
  - Spheres
  - Planes
  - Cylinders
  - Cones (bonus)
  - Cubes (bonus)

- **Lighting:**
  - Ambient lighting
  - Diffuse lighting
  - Specular highlights
  - Multiple light sources
  - Shadow casting

- **Materials:**
  - Solid colors
  - Color gradients
  - Reflection coefficients
  - Transparency (bonus)

- **Camera Controls:**
  - Perspective projection
  - Adjustable field of view
  - Variable image resolution

## 📦 Project Structure

```
minirt/
├── Makefile
├── inc/
│   ├── minirt.h     # Main header
│   └── struct.h     # Data structures
├── src/
│   ├── main.c
│   ├── parser/      # Scene file parsing
│   ├── raytracing/  # Ray tracing core
│   ├── colors/      # Color operations
│   ├── figures/     # Geometric objects
│   ├── utils/       # Utility functions
│   └── window/      # Display/rendering
├── scenes/          # Example scene files (.rt)
└── lib/             # External libraries (MLX, libft)
```

## 🗂️ Scene File Format

**.rt files** define the scene:

```
# Viewport size
R 1920 1080

# Ambient light
A 0.2 255,255,255

# Camera: position, direction, FOV
c -10,0,10 0,0,0 70

# Light: position, intensity, color
l 0,10,10 0.8 255,255,255

# Sphere: center, diameter, color
sp 0,0,20 20 255,0,0

# Plane: position, normal, color
pl 0,0,0 0,1,0 0,255,0

# Cylinder: position, axis, diameter, height, color
cy 0,0,0 0,1,0 10 20 0,0,255
```

## 🚀 Compilation & Execution

### Compilation

```bash
make
```

Creates executable: `minirt`

### Usage

```bash
./minirt <scene_file.rt>
```

### Example

```bash
./minirt scenes/basic.rt
```

## 🎮 Controls (if interactive)

- **Arrow Keys** - Move camera
- **Mouse** - Rotate camera view
- **+/-** - Zoom in/out
- **ESC** - Exit program
- **S** - Save screenshot

## 🧮 Ray Tracing Algorithm

1. **Initialization:** Load scene and set up camera
2. **Ray Generation:** Generate ray for each pixel
3. **Intersection:** Find nearest object intersection
4. **Lighting:** Calculate color using Phong model:
   - Ambient = intensity × color
   - Diffuse = max(0, normal·light) × color
   - Specular = max(0, reflect·view)^shine × color
5. **Shadow Checking:** Trace shadow rays to lights
6. **Pixel Output:** Write computed color to image

## 🔑 Key Concepts

- **Ray-Object Intersection** - Mathematical algorithms for each object type
- **Lighting Models** - Phong shading, shadows
- **Vector Mathematics** - Dot product, cross product, normalization
- **Matrix Transformations** - Rotation, translation, scaling
- **Color Blending** - RGB mixing and opacity
- **Performance Optimization** - Efficient ray tracing techniques

## 📐 Geometric Calculations

- **Ray-Sphere:** Quadratic equation solution
- **Ray-Plane:** Linear equation solution
- **Ray-Cylinder:** Complex quadratic with bounds checking
- **Lighting:** Angle calculations and shadow testing

## 🎨 Example Scenes

- `basic.rt` - Simple sphere and plane
- `multi_light_color_mix.rt` - Multiple light sources
- `shadow_test_scene.rt` - Shadow demonstration
- `cylinder.rt` - Cylinder rendering
- `room.rt` - Complex indoor scene

## 🛡️ Input Validation

- Validates scene file format
- Checks object parameters
- Validates color ranges (0-255)
- Ensures valid camera configuration

## 🔧 Compilation Details

```bash
make              # Build executable
make clean        # Remove object files
make fclean       # Remove executable and objects
make re           # Clean and rebuild
make bonus        # Include bonus objects (if available)
```

## 📚 Learning Points

- 3D mathematics and vectors
- Ray tracing algorithm fundamentals
- Lighting and shading models
- Geometric intersection calculations
- Performance optimization techniques
- Graphics library usage (MLX)

## 💡 Bonus Features (if applicable)

- Reflections and refractions
- Additional geometric shapes
- Advanced material properties
- Anti-aliasing
- Motion blur
- Texture mapping

## 📊 Performance Notes

- Optimized ray-object intersection tests
- Efficient shadow ray calculations
- Proper memory management
- Handles complex scenes smoothly

## 📝 Notes

- Scene files must be properly formatted
- Color values should be 0-255
- Viewport resolution affects quality and speed
- Multiple scenes provided for testing
- Can generate PPM or PNG images (bonus)
