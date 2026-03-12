<h1 align="center">cub3D</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-complete-brightgreen.svg" alt="Status">
</p>

<p align="center">
  A first-person 3D maze game built from scratch in C using ray-casting — inspired by the original Wolfenstein 3D engine.
</p>

<p align="center">
  <a href="README.pt-br.md">🇧🇷 Leia em Português</a>
</p>

---

## Why this project matters

> "This project taught me how the first 3D games were actually rendered — using ray-casting instead of a real 3D engine, projecting a 2D map into a 3D perspective in real time. I learned the math behind field of view, angular projection, texture mapping, and game loop design. This is the foundation of every graphics engine, from game development to augmented reality."

Ray-casting is the original rendering optimization that made real-time 3D games possible in the early 90s. Understanding it gives you deep intuition for how modern rendering pipelines — including GPU shaders and AR engines — work.

---

## Preview

A first-person perspective rendered from a `.cub` map file:

```
111111
100001
1N0001
100001
111111
```

- `1` = wall
- `0` = open space
- `N/S/E/W` = player spawn + initial facing direction

---

## What was built

- **Ray-caster** — casts rays from the player's POV to calculate wall distances and heights
- **Texture rendering** — loads `.xpm` textures and maps them onto walls based on ray hit position
- **Map validator** — verifies the map is fully enclosed, has exactly one player, and only valid characters
- **Movement system** — WASD movement + left/right rotation with collision detection
- **Minimap** (bonus) — real-time overhead view of the maze
- **Color rendering** — configurable floor and ceiling colors from the `.cub` file

---

## A standout technical detail

The project is organized into distinct subsystems — `raycast/`, `validate_map/`, `interpretate_map/`, `texture/`, `color/`, `movements/`, `minimap/` — each in its own directory with focused responsibilities. This kind of domain-driven directory structure scales well and makes the codebase navigable, a pattern seen in production game engines and large C projects.

---

## Getting Started

### Prerequisites

```bash
# On Ubuntu/Debian
sudo apt-get install libxext-dev libx11-dev libmlx-dev
```

```bash
git clone https://github.com/gustavofsousa/cub3D.git
cd cub3D
make
```

### Running

```bash
./cub3D maps/map1.cub
```

### Map format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1N0001
100001
111111
```

### Controls

| Key | Action |
|---|---|
| `W` `A` `S` `D` | Move forward / strafe left / backward / strafe right |
| `←` `→` | Rotate camera |
| `ESC` | Quit |

---

## Project structure

```
cub3D/
├── source/
│   ├── main.c
│   ├── setup.c
│   ├── render_game.c
│   ├── raycast/          # Ray-casting algorithm
│   ├── texture/          # XPM texture loading and mapping
│   ├── color/            # Floor/ceiling color rendering
│   ├── validate_map/     # Map validation logic
│   ├── interpretate_map/ # Map file parsing
│   ├── movements/        # Player movement and collision
│   ├── minimap/          # Bonus: overhead minimap
│   └── hooks_keyboard.c  # Input handling
├── include/
│   ├── cub3d.h
│   ├── structs.h
│   └── constants.h
├── maps/                 # Sample .cub map files
├── textures/             # XPM texture files
└── libft/
```

---

## Skills demonstrated

- Ray-casting rendering algorithm (DDA — Digital Differential Analysis)
- XPM texture loading and pixel-level mapping
- Real-time game loop with keyboard event handling
- Complex map validation (flood fill, boundary checking)
- Modular architecture in a large multi-file C project
- Trigonometry applied to camera projection (FOV, angle calculations)

---

## License

This project was developed as part of the [42 School](https://42.fr) curriculum.

---

<p align="center">Made with ☕ at 42 Rio de Janeiro</p>
