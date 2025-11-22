# F0X Game

A awesome OpenGL game built with C++!

## Description

This project is a simple OpenGL-based game demonstrating modern C++ game development techniques, including model loading with Assimp, GLFW for windowing, and OpenGL rendering.

## Prerequisites

Before building the project, make sure you have the required tools and libraries installed.

### Windows
All necessary static libraries are included in the `/lib` folder. To build and run the project:

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build . --config Release
./F0X.exe
```

### Linux

You need to install the required system libraries. On Ubuntu/Debian, you can run:
```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libassimp-dev zlib1g-dev
```

Then build and run:

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./F0X
```

## Notes

* On Windows, the included static libraries allow building without installing additional dependencies.
* On Linux, the system packages handle all required dependencies.
* Always make sure the resources paths in your code match the executable's working directory.
