# Conways-GameOfLife
This is my simulation of Conway's Game Of Life in C++ using SDL.This project provides a simple and interactive visualization of the classic cellular automaton.<br>
For more info about Conway's Game of Life Go To- [Wikipedia](https://en.wikipedia.org/wiki/Conway's_Game_of_Life).

## Gif Of My Implementation
![Conway'sGameOfLife](https://github.com/NaitikRathi/Conways-GameOfLife/assets/84074226/d5a95589-7b6f-4ca1-a77f-00c18cbc0336)

## Getting Started To Edit
### Prerequisites
- C++ Compiler
- SDL2 Library
Download The repo and Edit it as you want

## Running
Just go to Build/ConwayGameOfLife.exe and run it.
- The Game of Life starts with a random initial configuration of live cells.
- Watch the cells evolve based on the following rules:
  - Any live cell with fewer than two live neighbors dies (underpopulation).
  - Any live cell with two or three live neighbors survives.
  - Any live cell with more than three live neighbors dies (overpopulation).
  - Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## Code Structure
- **main.cpp:** Entry point of the program, initializes SDL2 and contains the main game loop.
- **LifeData.h / LifeData.cpp:** Defines and initializes the game board and provides utility functions for board manipulation.
- **TheLifePart.h / TheLifePart.cpp:** Handles the logic for updating the game state based on the rules of Conway's Game of Life.

## Customization
Feel free to modify the code to experiment with different board sizes, initial configurations, or tweak the game loop speed.
