# cub3D 🎮

A 3D raycasting game inspired by Wolfenstein 3D, built in C as part of the 42 school curriculum.

## Overview

cub3D uses the raycasting technique to render a first-person 3D perspective of a 2D map. It features textured walls, colored floors and ceilings, a minimap HUD, player movement with collision detection, and themed maps with ambient audio.

## Features

- **Raycasting engine** — first-person 3D rendering with correct perspective
- **Directional wall textures** — unique PNG textures for North, South, East, and West walls
- **Floor & ceiling colors** — configurable per-map RGB colors
- **Minimap HUD** — scaled overhead view rendered in the corner of the screen
- **Player movement** — smooth WASD movement with wall collision detection
- **Player rotation** — look left/right via arrow keys or ESC to quit
- **Three themed maps** — Café, Chopin, and Sea, each with custom textures and audio
- **Ambient audio** — background sound per map (macOS only via `afplay`)

## Screenshots

> Three playable scenes: `cafe.cub`, `chopin.cub`, and `sea.cub`

| Café | Chopin | Sea |
|------|--------|-----|
| Warm brick walls, café sounds | Grand piano hall | Underwater ocean world |

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate left |
| `→` | Rotate right |
| `ESC` | Exit the game |

## Dependencies

- [MLX42](https://github.com/codam-coding-college/MLX42) — OpenGL-based graphics library (included as a git submodule)
- [GLFW](https://www.glfw.org/) — Required by MLX42 (must be installed on your system)
- [cmake](https://cmake.org/) — Required to build MLX42
- [libft](https://github.com/fritz-gabler/libs) — Custom C utility library (included as a git submodule)

### Install GLFW

**macOS (Homebrew):**
```bash
brew install glfw
```

**Linux (apt):**
```bash
sudo apt-get install libglfw3-dev
```

## Building

Clone the repository with its submodules:

```bash
git clone --recurse-submodules https://github.com/fritz-gabler/cub3d.git
cd cub3d
```

Build the project:

```bash
make
```

| Target | Description |
|--------|-------------|
| `make` | Build the `cub3D` binary |
| `make clean` | Remove compiled object files |
| `make fclean` | Remove object files and the binary |
| `make re` | Full rebuild (`fclean` + `all`) |

## Usage

```bash
./cub3D <path/to/map.cub>
```

**Examples:**

```bash
./cub3D maps/cafe.cub
./cub3D maps/chopin.cub
./cub3D maps/sea.cub
```

## Map Format (`.cub`)

A `.cub` scene file defines textures, colors, and the map layout.

### Configuration

```
NO ./path/to/north_texture.png   # North wall texture
SO ./path/to/south_texture.png   # South wall texture
WE ./path/to/west_texture.png    # West wall texture
EA ./path/to/east_texture.png    # East wall texture

F R,G,B                          # Floor color (e.g. F 193,154,107)
C R,G,B                          # Ceiling color (e.g. C 245,245,220)
```

### Map Grid

```
1111111
1000001
100N001    <- N = player start facing North
1000001
1111111
```

| Symbol | Meaning |
|--------|---------|
| `1` | Wall |
| `0` | Walkable floor |
| `N` `S` `E` `W` | Player start position and facing direction |
| ` ` (space) | Outside / void (must be enclosed by walls) |

**Rules:**
- The map must be surrounded by walls (`1`).
- The file must contain exactly one player start position.
- Texture and color declarations must appear before the map.

## Project Structure

```
cub3d/
├── src/
│   ├── cub3d.c                  # Entry point
│   ├── parsing/                 # Map and config file parsing
│   ├── raycaster/               # Raycasting math (horizontal/vertical intersections)
│   ├── render/                  # Wall rendering and texture mapping
│   ├── minimap/                 # Minimap HUD rendering
│   ├── hooks/                   # Keyboard input and movement
│   ├── init/                    # Game initialization and launch
│   ├── exit/                    # Clean shutdown
│   └── free_structs/            # Memory cleanup
├── include/
│   ├── cub3d.h                  # Main header (defines, constants)
│   ├── structures.h             # All struct definitions
│   ├── functions.h              # Function prototypes
│   ├── color.h                  # Color utilities
│   └── error_message.h          # Error message strings
├── maps/
│   ├── cafe.cub
│   ├── chopin.cub
│   └── sea.cub
├── assets/                      # Textures and audio per theme
├── MLX42/                       # Graphics library (submodule)
├── libs/                        # Custom C library — libft (submodule)
└── Makefile
```

## Authors

- **fritz-gabler** — [GitHub](https://github.com/fritz-gabler)
- **hkumbhan** — 42 Heilbronn

*42 School project — 2024*
