# Goldmine — Console-Based Treasure Hunt Game

## Overview

Goldmine is an interactive, terminal-based treasure hunt game built in C++. Players navigate a 6×6 grid, strategically selecting cells to uncover hidden items — gold, a rainbow clue, or coal — while managing a diminishing gold reserve. The game combines randomized board generation with risk-reward decision-making, delivering a replayable experience entirely from the command line.

## Key Features

- **Randomized 6×6 Game Board** — Each round generates a fresh board with randomly placed gold, rainbow, and coal tiles, ensuring no two games are alike.
- **Risk-Reward Gameplay** — Every unsuccessful dig costs the player a random amount of gold, creating tension between exploration and preservation.
- **Rainbow Hint System** — Discovering the rainbow tile reveals the quadrant where the gold is hidden (upper-left, upper-right, lower-left, lower-right), adding a layer of strategy.
- **Win/Lose Conditions** — Find the gold to win with a massive payout, hit the coal to lose instantly, or run out of gold trying.
- **Replayable Game Loop** — After each round, players can immediately start a new game without restarting the program.
- **Generic 2D Array Template** — Uses a custom C++ class template (`twoDim<T>`) for type-safe, reusable two-dimensional array management across the game's data layers.

## Tech Stack

| Component       | Technology       |
|-----------------|------------------|
| Language        | C++ (C++11+)     |
| Build           | g++ / any standard C++ compiler |
| Platform        | Cross-platform (Linux, macOS, Windows) |
| Dependencies    | Standard Library only (`<iostream>`, `<string>`, `<cstdlib>`) |

## System Architecture

The project follows a clean separation of concerns across three modules:

```
playgame.cpp          → Entry point & game loop (user I/O, menu logic)
    │
    ├── Goldmine.h/.cpp   → Core game engine (board state, reveal logic, hints)
    │       │
    │       └── twoDim.h/.cpp → Generic 2D array template (data storage layer)
    │
    └── User Input ←→ Console Output
```

**Data flow:**
1. `playgame.cpp` initializes a `Goldmine` instance and drives the main game loop.
2. `Goldmine::resetGame()` populates three parallel 2D arrays — `visited` (bool), `boxType` (char), and `goldAmount` (int) — with randomized values.
3. On each turn, the player selects a row and column; `revealSelection()` resolves the outcome based on the cell's hidden type.
4. The board is re-rendered after each move via `printGoldMine()`, masking unvisited cells.

## Setup & Installation

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, MSVC)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/samie-mirghani/goldmine.git
cd goldmine

# Compile
g++ -o goldmine playgame.cpp Goldmine.cpp -std=c++11

# Run
./goldmine
```

### How to Play

1. The game displays a 6×6 grid of hidden cells (shown as `*`).
2. Enter a row (1–6) and column (1–6) to dig at that location.
3. Possible outcomes:
   - **Nothing** (`-`) — You lose a random amount of gold.
   - **Rainbow** (`R`) — You receive a hint about which quadrant contains the gold.
   - **Gold** (`G`) — You win the game!
   - **Coal** (`C`) — You lose the game instantly.
4. After a win or loss, choose whether to play again.

## Suggested Topics / Tags

`cpp` · `game` · `console-game` · `terminal-game` · `treasure-hunt` · `grid-game` · `command-line` · `beginner-project`

## Author

Shamsadean Mirghani

## License

This project is provided for educational purposes.
