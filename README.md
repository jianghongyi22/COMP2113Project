# Snake Game — COMP2113 Project

A terminal-based Snake Game written in C++. Control a snake to eat apples, avoid walls and self-collision, and chase high scores across four difficulty levels.

---

## Team members

- Jiang Hongyi UID: 3036480191
    Role: Logic of apple, board, snake entities, input processing and top score saving. 
- Zhang Zhanhao UID: 3036482113 
    Role: Logic of the game, score class, programme entry and makefile.

## Features

- **Classic snake movement** with arrow keys; 180-degree turn is blocked
- **Two apple types**: normal apples (`*`, +1 point, grow by 1) and golden apples (`#`, decaying bonus points starting at 12, no snake length growth)
- **Pause and resume** (`P` key) and **quit** (`Q` key)
- **Four difficulty levels** — Easy, Medium, Hard, Insane — controlling game speed via a text file
- **Configurable board size** via a text file
- **Persistent top-5 high scores** top-5 scores saved to a text file
- **Real-time rendering** using ANSI escape sequences and non-blocking terminal input

---

## How Each Required Coding Element Supports the Game

### 1. Generation of Random Events

- New apples are placed at random positions (not on the snake).

### 2. Data Structures for Storing Data

- **`std::vector<std::pair<int, int>>`** — The snake's body is a vector of (row, column) pairs in [snake.cpp](snake.cpp).
- **`std::pair<int, int>`** — Used throughout the codebase for 2D coordinates.
- **Enumerations** — `Direction` (UP/DOWN/LEFT/RIGHT), `AppleType` (NORMAL/GOLDEN), `Key` (arrow/action mapping), and `Difficulty` (EASY/MEDIUM/HARD/INSANE/INVALID) provide type-safe constants.
- **`std::vector<int>`** — Used in [file_output.cpp](file_output.cpp) to store the list of high scores read from or written to the text file.
- **Classes** - `Apple`, `Board`, `Game`, `Input`, `Score`, `Snake` classes are used for storing attributes and methods.

### 3. Dynamic Memory Management

- Apple objects (`Apple`) are allocated with `new` when spawned and deallocated with `delete` when eaten, expired or game is over.

### 4. File I/O

- **Configuration reading** — [main.cpp](main.cpp) `readConfig()` reads `input.txt` at startup to determine the board dimensions (width and height, 10–30) and the difficulty level. Invalid inputs are handled.
- **Score loading** — [score.cpp](score.cpp) `load()` reads the current best score from `record.txt` when the game starts.
- **Score saving** - [file_output.cpp](file_output.cpp) `updateHighestScores` keeps top-5 scores in `record.txt`.

### 5. Program Codes in Multiple Files

The project is split into 8 modules:

| Module | Purpose |
|---|---|
| `main.cpp` | Entry point and configuration parsing |
| `game.cpp` / `game.h` | Core game loop, rendering, apple spawning, scoring |
| `snake.cpp` / `snake.h` | Snake data structure, movement, growth, collision |
| `apple.cpp` / `apple.h` | Apple position, type, point calculation, expiration |
| `board.cpp` / `board.h` | Board boundary rendering and boundary checking |
| `input.cpp` / `input.h` | Terminal raw-mode setup and non-blocking key input |
| `score.cpp` / `score.h` | Running score and best-score tracking |
| `file_output.cpp` / `file_output.h` | Read/Write highest scores |

### 6. Multiple Difficulty Levels

Four difficulty levels are defined as `enum class Difficulty` in [game.h](game.h). The level is read from `input.txt` and controls the speed of the game:

| Difficulty | Delay between moves |
|---|---|
| Easy | 250 ms |
| Medium | 200 ms |
| Hard | 150 ms |
| Insane | 50 ms |

---

## Non-Standard Libraries

| Header | Used In | Purpose |
|---|---|---|
| `<termios.h>` | [input.cpp](input.cpp) | Configure terminal raw mode (disable line buffering and echo) |
| `<unistd.h>` | [input.cpp](input.cpp) | `read()` system call and `STDIN_FILENO` for non-blocking keyboard input |
| `<fcntl.h>` | [input.cpp](input.cpp) | `fcntl()` with `O_NONBLOCK` to read keystrokes without blocking |

These are POSIX headers available on **Linux and macOS**. The game does not run natively on Windows.

---

## Quick Start

### Prerequisites

- **g++** (C++11 or later)
- **make**
- A POSIX-compatible terminal (Linux, macOS, or WSL on Windows)

### Configure the Game

Edit `input.txt` in the project root or use default config:

```
20 20
hard
```

- Line 1: board width and height (integers, 10–30)
- Line 2: difficulty — one of `easy`, `medium`, `hard`, `insane`

### Build and Run

```bash
make          # compile
make run      # compile and run
./snake_game  # run directly after build
make clean    # remove .o files and snake_game
```

### Controls

| Key | Action |
|---|---|
| Arrow keys | Change snake direction |
| `P` | Pause / Resume |
| `Q` | Quit game |
