# So_Long [42 Project]
This 42 project challenges us to create a small 2D game with a specific library called MiniLibX.

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Dependencies](#dependencies)
4. [How to Use](#how-to-use)
5. [Game Example](#game-example)
6. [Contributing](#contributing)

## Overview
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

### Game Rules
-The player’s goal is to collect every collectible present on the map, then escape choosing the shortest possible route.
- The `W`, `A`, `S`, and `D` keys must be used to move the main character.
- The player should be able to move in these 4 directions: `up`, `down`, `left`, `right`.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).
- The game doesn’t have to be real time.

### Graphic management
- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing `ESC` must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.

### Map Rules
- The map has to be constructed with 3 components: walls, collectibles, and empty space.
- The map can be composed of only these 5 characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for a map exit
  - `P` for the player’s starting position
Here is a valid map:
```bash
1111111
1P00001
10C00E1
1111111
```
- The map must contain 1 `E`, 1 `C` and 1 `P`.
- The map must be rectangular, closed by `1` and must have a valid path
- The map needs to be a file with the `.ber` extension
- If any misconfiguration is encountered the game must return an Error message

## Project Structure
- `so_long/`: Main directory containing the following directories and files:
  - `src/`: Contains all the source code.
  - `map/`: Contains all valid and invalid maps.
  - `sprites/`: Contains all the sprites being used.
  - `libft/`: Contains the libft library with get_next_line and ft_printf libraries.
  - `include/`: Contains the header file.
  - `Makefile`: Build automation script

## Dependencies
- Libft (already included)
- [MiniLibX](https://github.com/42Paris/minilibx-linux)

## How to Use
1. Clone the repository.
2. Navigate to the `so_long` directory: `cd so_long/`.
3. Compile the game: `make`.
4. Run the game: `./so_long map/valid/any_map`.
If you choose an invalid map, you will receive an error message.

## Game Example
![Game Image](https://private-user-images.githubusercontent.com/131177558/302682779-fb526c43-d2f7-4ea7-b4a8-e262ec9af2bd.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MDcyMzM1NTcsIm5iZiI6MTcwNzIzMzI1NywicGF0aCI6Ii8xMzExNzc1NTgvMzAyNjgyNzc5LWZiNTI2YzQzLWQyZjctNGVhNy1iNGE4LWUyNjJlYzlhZjJiZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMjA2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDIwNlQxNTI3MzdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zNTYwZDA2NmU3ZjUzNjRiMzMwZDc0YmQzZmU3N2MzOGMwMGExNjgwNTJhNGU4NjE1ZGIxYTRlMzhmOGZmNmY2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.ItXEqv_gOOMiWy8Sv6k9d9m2DO-tmjhcrWh6Waq7ubk)

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
