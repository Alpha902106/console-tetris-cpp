# console-tetris-cpp

A console-based implementation of the classic Tetris game written in C++ using the Windows Console API.

This project was created as a learning-focused software engineering exercise to understand real-time input handling, game loops, collision detection, and incremental improvement using Git.

---

## Overview

The game runs entirely inside a Windows console window and renders graphics using a custom screen buffer.  
It implements core Tetris mechanics including piece rotation, gravity, collision handling, line clearing, and scoring.

The primary goal of this project is correctness, clarity, and progressive refinement rather than visual polish.

---

## Features

- Seven standard tetromino pieces
- 4×4 matrix-based rotation logic
- Pivot-safe rotation with ground correction
- Responsive keyboard input with repeat-delay control
- Soft drop support
- Automatic gravity-based falling
- Dynamic difficulty scaling based on cleared lines
- Line detection, clearing, and scoring
- Collision detection with walls and locked blocks
- Game-over screen with final score display

---

## Controls

| Key | Action |
|-----|-------|
| Left Arrow | Move piece left |
| Right Arrow | Move piece right |
| Down Arrow | Soft drop |
| Up Arrow | Rotate piece |
| Automatic | Gravity-based falling |

---

## Build and Run Instructions

### Requirements
- Windows operating system
- Microsoft Visual Studio
- C++ Desktop Development workload installed

### Steps
1. Open Visual Studio
2. Create a new **Console Application (C++)**
3. Replace the generated source file with `TETRIS.cpp` from this repository
4. Build and run the program using **Ctrl + F5**

Note: This project uses `Windows.h` and is not designed to be cross-platform.

---

## Technical Highlights

- Game loop with timing-based gravity control
- Input handling using `GetAsyncKeyState` with throttling
- Rotation logic using indexed 4×4 matrices
- Collision validation against a bounded playfield
- Manual memory management for field and screen buffers
- Console rendering via `CreateConsoleScreenBuffer` and `WriteConsoleOutputCharacterW`

---

## Project Structure

