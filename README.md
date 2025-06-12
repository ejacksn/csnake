# Terminal Snake Game in C 

This is a simple implementation of the classic Snake game in the terminal, written in C using the `ncurses` library.

## Gameplay

- Use **arrow keys** to control the snake (`↑ ↓ ← →`)
- Eat apples (`@`) to grow your snake and increase your score
- Avoid hitting the walls (`X`) or yourself!
- Press **`q`** to quit at any time

##  Features

- Dynamic snake movement and growth
- Apple spawning with collision avoidance
- Self-collision and wall detection
- Real-time keyboard input using `ncurses`
- Game runs at a smooth refresh interval (`napms`-based)

##  Requirements

- C compiler (e.g. `gcc`)
- `ncurses` library installed (Linux/macOS):
  ```bash
  sudo apt install libncurses5-dev libncursesw5-dev  # for Ubuntu
  


##BUILD INSTRUCTIONS
# Clone the repo

# Generate build files
cmake -S . -B build

# Build the game
cmake --build build

# Run it
./build/snake_game