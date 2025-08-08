# LibYetzirah

> ✨ Cross-platform 2D/3D Game Engine in modern C++  
> Modular, OpenGL-powered engine for scalable games with ECS, physics, and rendering pipelines.

---

## 🧭 Overview

**LibYetzirah** is a high-performance **2D and 3D game engine** written in modern C++, designed for building scalable, real-time applications.  
It combines a modular architecture with **OpenGL 3.3+**, a custom **Entity Component System (ECS)**, and optional physics/scripting layers.

Suitable for everything from top-down 2D games to 3D environments, simulations, and hybrid projects.

---

## ✨ Features

- 📦 Unified 2D/3D rendering pipeline (OpenGL 3.3+)
- 🧩 Custom ECS framework
- 🖼️ Texture & mesh management
- 🎮 Input abstraction (mouse, keyboard, gamepad)
- 🎙️ Audio system via SDL_mixer
- 🔄 Scene graph and transformation system
- 🧲 Physics integration (2D & 3D via Box2D / Bullet)
- 🧠 Lua scripting (optional)
- 🛠️ In-engine debug tools and editor stubs (WIP)

---

## ⚙️ Requirements

- C++17 or later
- CMake 3.15+
- SDL2
- OpenGL 3.3+
- GLM (math library)
- SDL_image, SDL_mixer, SDL_ttf
- Optional: ImGui, Bullet Physics, Lua

---

## 🔧 Build Instructions

1. **Clone the repository**

```bash
git clone https://github.com/your-org/libyetzirah.git
cd libyetzirah
```

2. **Configure and build**

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

3. **Run a demo**

```bash
./libyetzirah-demo
```

---

## 🗂️ Project Structure

```plaintext
src/
├── core/         → Engine loop, config, time
├── renderer/     → OpenGL renderer, shaders, buffers
├── ecs/          → Entity Component System
├── input/        → Input manager
├── audio/        → Audio handling
├── physics/      → Physics abstraction (Box2D / Bullet)
├── scripting/    → Lua integration (optional)
├── scene/        → Scene and hierarchy system
examples/         → Demos in 2D and 3D
include/          → Public headers
```

---

## 🔐 License

This project is released under the **MIT License**.  
© Gaming Innovators — Empowering scalable 2D/3D game development with modern C++.

---

## 🤝 Credits

- OpenGL
- SDL2
- GLM
- Box2D / Bullet
- Lua
- ImGui
