# C Mini Projects

A collection of small, practical C programs built while learning C in my first year of B.E. Electronics and Communication Engineering at Chennai Institute of Technology. Each program is a self-contained mini project that puts core C concepts to real use: loops, functions, strings, conditionals, random numbers, time handling and file I/O.

## Projects

| # | Project | What it does | Key concepts |
|---|---------|--------------|--------------|
| 1 | [Clock](clock.c) | Displays the current time in the terminal | `time.h`, loops, formatted output |
| 2 | [Timer](timer.c) | Counts down (or up) for a duration you enter | Loops, delays, user input |
| 3 | [Colour Code Converter](colour.c) | Converts colour codes between formats such as RGB and HEX | Number systems, `printf`/`scanf` format specifiers, functions |
| 4 | [Password Generator](password_generator.c) | Generates random passwords of a chosen length | `rand()`, `srand()`, arrays, character sets |
| 5 | [Quote Generator](quotegenerator.c) | Reads quotes from a text file and shows a random one | File handling, `fopen`/`fgets`, randomness |
| 6 | [To-Do List](todos.c) | Add, view and delete tasks that are saved between runs | File handling, structures/strings, menu-driven design |
| 7 | [Number Guessing Game](numberguessinggame.c) | Guess a random number with higher/lower hints | `rand()`, loops, conditionals |

## Repository Structure

```
C-Mini-Projects/
├── clock.c
├── timer.c
├── colour.c
├── password_generator.c
├── quotegenerator.c
├── quotes.txt          # data file used by the quote generator
├── todos.c
├── todos.txt           # data file used by the to-do list
├── numberguessinggame.c
└── README.md
```

## Getting Started

### Prerequisites

A C compiler such as GCC.

- **Windows:** install [MinGW](https://www.mingw-w64.org/) or use Code::Blocks / Dev-C++
- **Linux:** `sudo apt install gcc`
- **macOS:** `xcode-select --install`

Check your installation:

```bash
gcc --version
```

### Clone the repository

```bash
git clone https://github.com/BaraniharanV/C-Mini-Projects.git
cd C-Mini-Projects
```

### Compile and run

```bash
gcc clock.c -o clock
./clock            # Linux/macOS
clock.exe          # Windows
```

Replace `clock` with any program name. For programs that read files (quote generator, to-do list), run them from the repository folder so they can find `quotes.txt` and `todos.txt`.

## Project Details

### 1. Clock
A terminal clock that shows the current system time and keeps updating it.

### 2. Timer
Enter a time and the program counts it down, then alerts you when it reaches zero.

### 3. Colour Code Converter
Converts colour values from one format to another (for example, RGB to HEX). Useful for web design and electronics display work.

### 4. Password Generator
Creates a random password from uppercase letters, lowercase letters, digits and symbols. You choose the length.

### 5. Quote Generator
Stores quotes in a text file and prints a random one each time you run it. To add your own, append a new line to `quotes.txt`.

### 6. To-Do List
A menu-driven task manager. Tasks are saved to `todos.txt`, so they are still there the next time you run the program.

### 7. Number Guessing Game
The computer picks a secret number and you try to guess it. After each guess, you get a hint of "too high" or "too low".

## What I Learned

- Structuring programs with functions and menus
- Generating random values with `rand()` and `srand()`
- Reading and writing files for persistent data
- Working with time in C
- Handling user input and validating it
- Compiling, running and debugging programs with GCC

## Future Improvements

- Add input validation to every program
- Add colours and a cleaner terminal interface
- Add edit/mark-as-done options to the to-do list
- Add difficulty levels to the guessing game
- Add a lap/pause feature to the timer

## Contributing

Suggestions and improvements are welcome. Fork the repo, make your changes and open a pull request, or open an issue to discuss an idea.

## Author

**Baraniharan V**
B.E. Electronics and Communication Engineering, Chennai Institute of Technology
GitHub: [@BaraniharanV](https://github.com/BaraniharanV)
