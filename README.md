# FdF

<p align="center">
  <img src="https://github.com/cyan-wings/FdF/blob/main/fdf.png" alt="FDF 42 project badge"/>
</p>

FDF is short for ’fil de fer’ in French which means ’wireframe model’. FdF offers to represent “iron wire” meshing in 3D.

## Project brief

FdF renders an input file with a grid of height values into a 3D wireframe model using [MinilibX](https://github.com/42Paris/minilibx-linux), a simple abstraction of the X-Window (X11R6) programming API in C.

<b>Allowed functions:</b>
1. Anything from the math C library. (Though not used in this project)
2. `open, close, read, write, malloc, free, perror, strerror, exit`
3. Functions from MinilibX.

## Features

<b>Project fulfills mandatory requirements and bonus requirements + some add ons!</b>

### Rendering:
- Custom Math library (refer libft/includes/ft_math_utils)
- Orientation of model is represented using quaternions
- Lines drawn using Xiaolin Wu's line algorithm for antialiasing
- Simple animations when changing projections using quaternion slerp
- Color interpolation when an edge connects 2 different colored vertices

### Controls:
- `ESC` -> Exit Program
- `ARROW_LEFT / ARROW_RIGHT` -> Zoom Out / In
- `ARROW_UP / ARROW_DOWN` -> Scale Up /Down Height
- `Q / E` -> Rotate Clockwise / Counter Clockwise
- `W / A / S / D` -> Translates Model Up / Left / Down / Right
- `I` -> Isometric Projection
- `O` -> Orthogonal Projection
- `P` -> Perspective Projection

## How to use

FdF currently works on all UNIX based systems (i.e., macOS, Linux, WSL).

<b>Requirements:</b>
- GCC / CLANG Compiler
- GNU Make

For Linux or WSL
```
sudo apt install libx11-dev libxext-dev zlib1g-dev
```

For macOS:
`-framework OpenGL` and `-framework AppKit` s should be part of the OS, hence no installation likely required

<b>Compiling FdF:</b>
```
git clone https://github.com/cyan-wings/FdF FdF
cd FdF && make
```

<b>Running a test map:</b>
- Test maps can be found in the `specs/test_maps/` directory
```
./FdF specs/test_maps/test.fdf
```

- Alternatively, a map can be written as long as it matches the format of a .fdf file and must be rectangular
```
./FdF path/of/custom_map.fdf
```

- To run every single test available in the `specs/test_maps/` directory:
```
make run
```

## Examples

The following is an example of a .fdf file we use as an input for our program:
```
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xff 15,0xff 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```

which yields

<img width="1236" alt="Fdf example" src="">


Special TODOs for the future:
1. Reset button back to the original starting projection.
2. Fix color linear interpolation bug due to Xiaolin Wu's algorithm point swapping.
3. Implement HSV color interpolation instead of the current RGB.
4. Create some mouse hooks especially scrolling.
5. Implement rotations on x and y axis or other axis planes.
6. Implement a function to change the default color in the program.
