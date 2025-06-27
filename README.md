# Ray Tracer with OpenGL & ImGui Interface

A custom C++ ray tracer based on the ["Ray Tracing in One Weekend"](https://raytracing.github.io/) series, enhanced with an OpenGL & ImGui-based GUI. This application renders ray-traced images into `.ppm` files and displays them in an OpenGL window, providing interactive parameter controls through ImGui. It is **not a real-time renderer**—changes via the UI re-trigger the rendering process and reload the resulting image.

---

## 📌 Introduction

This project implements a CPU-based ray tracer with a graphical frontend. The renderer is heavily inspired by the *Ray Tracing in One Weekend* book series, but extended with additional features and a graphical interface to make experimentation easier.

### Key Features

- CPU-based ray tracing using C++
- OpenGL window for rendering image previews
- ImGui interface for:
  - Changing render settings (resolution, samples, etc.)
  - Modifying scene parameters
  - Triggering a new render
- Supports `.ppm` output format

---

## 🛠️ Installation

### 🛠 Prerequisites

Make sure you have the following tools installed:

- **CMake** (>= 3.15)
- **g++ / clang++ / MSVC** with C++17 support
- **Git**
- **OpenGL 3.3+ compatible GPU**

All required dependencies (GLFW, GLAD, stb_image, ImGui) are already included in the `external/` folder. No package managers or submodules are needed.

### 🧱 Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/ray-tracer.git
cd ray-tracer

# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

---

## 🚀 Usage

*To be added...*

---

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

