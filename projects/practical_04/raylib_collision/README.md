# Raylib Collision Kit <a name="raylib-collision-kit"></a>

A cross-platform collision detection toolkit built with Raylib, providing ready-to-use collision detection implementations for 2D games. This toolkit enables developers to quickly implement and visualise various collision detection techniques in their games.

## Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
  - [Linux Installation](#linux-installation)
  - [Windows Installation](#windows-installation)
  - [macOS Installation](#macos-installation)
- [Building and Running](#building-and-running)
- [Collision Features](#collision-features)
- [Example Usage](#example-usage)
- [Web Development](#web-development)
- [Resources](#resources)
- [Support](#support)

## Overview <a name="overview"></a>

This collision kit provides:

- Point vs Shape collision detection
- Circle vs Circle collision detection
- Rectangle vs Rectangle collision detection
- Visual debugging tools
- Cross-platform support (Linux, Windows, macOS)
- Web build support via Emscripten

   ```
   raylib_collision/
   ├── cute_headers/ 
   │   ├── cute_c2.h          # Main collision detection header
   │   └── game.h             # game loops methods
   ├── src/
   │   ├── main.c             # Demo application
   │   └── game.c             # game loops method implementationjs
   ├── template/
   │   └── template.html      # Web demo template
   ├── Makefile               # Build configuration
   └── README.md              # This file
   ```

## Prerequisites <a name="prerequisites"></a>

- C/C++ development environment
- CMake (3.0 or higher)
- Git
- Platform-specific build tools
- Python (for web server)

## Installation <a name="installation"></a>

### Linux Installation <a name="linux-installation"></a>

1. **Install Dependencies**
   ```bash
   # Update system packages
   sudo apt update
   sudo apt upgrade

   # Install build tools
   sudo apt install -y build-essential cmake git
   ```

2. **Clone and Setup**
   ```bash
   # Clone repository
   git clone https://MuddyGames@bitbucket.org/MuddyGames/raylib_collision.git
   cd raylib_collision

   # Build project
   make
   ```

### Windows Installation <a name="windows-installation"></a>

1. **Install MSYS2**

   - Download MSYS2 from [msys2.org](https://www.msys2.org/)
   - Run the installer
   - Open MSYS2 UCRT64 terminal

2. **Setup Development Environment**
   ```bash
   # Update package database
   pacman -Syu

   # Install required tools
   pacman -S git make mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake
   ```

3. **Clone and Build**
   ```bash
   git clone https://MuddyGames@bitbucket.org/MuddyGames/raylib_collision.git
   cd raylib_collision
   make
   ```

### macOS Installation <a name="macos-installation"></a>

1. **Install Dependencies**
   ```bash
   # Install Homebrew if needed
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

   # Install required packages
   brew update
   brew install cmake
   brew install gcc
   brew install git
   ```

2. **Clone and Build**
   ```bash
   git clone https://MuddyGames@bitbucket.org/MuddyGames/raylib_collision.git
   cd raylib_collision
   make
   ```

## Building and Running <a name="building-and-running"></a>

Use these make commands to build and run:

		```bash
		# Build all targets
		make all

		# Build desktop version
		make build

		# Run desktop version
		make run

		# Build web version
		make build_web

		# Run web version (starts local server)
		make run_web

		# Clean build files
		make clean

		# Build release version
		make CONFIG=release
		```

## Collision Features <a name="collision-features"></a>

The toolkit provides the following collision detection methods:

1. **Point Collision**

		- Point vs Circle
		- Point vs Rectangle
		- Point vs Line

2. **Circle Collision**

		- Circle vs Circle
		- Circle vs Rectangle
		- Circle vs Line

3. **Rectangle Collision**

		- Rectangle vs Rectangle
		- Rectangle vs Line
		- AABB collision

## Example Usage <a name="example-usage"></a>

Here's a basic example of circle collision detection:

		```c
		#include "collision.h"

		// Create two circles
		Circle circle1 = { 100, 100, 50 };  // x, y, radius
		Circle circle2 = { 200, 200, 30 };

		// Check for collision
		if (CheckCircleCollision(circle1, circle2)) {
			// Handle collision
			DrawCircleCollision(circle1, circle2);  // Visual debug
		}
		```

## Web Development <a name="web-development"></a>

To build and run the web version:

1. **Build for Web**
   ```bash
   make build_web
   ```

2. **Start Local Server**
   ```bash
   make run_web
   ```

3. Open `http://localhost:8000` in your browser

## Resources <a name="resources"></a>

- [Raylib Official Documentation](https://www.raylib.com/)
- [Collision Detection Tutorial](https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php)
- [2D Game Collision Detection](https://www.jeffreythompson.org/collision-detection/)

## Support <a name="support"></a>

For questions and support, contact:

- MuddyGames

[Back to top](#raylib-collision-kit)