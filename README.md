# Raycasting Maze Project

Welcome to the **Raycasting Maze Project**! This is a work-in-progress project aimed at creating a simple 3D maze game using raycasting principles, inspired by classic games like Wolfenstein 3D. The project is written in C and utilizes SDL for rendering the graphics, making it an exciting learning journey into the world of 2D-to-3D projection and game development.

## Features

- **2D Grid-Based Map**: The project uses a 2D grid to represent walls and empty spaces, where the player can explore and navigate through the maze.
- **Raycasting Engine**: Implements raycasting techniques to cast rays from the player's position and determine distances to walls, allowing for 3D visualization on a 2D grid.
- **Basic Texture Mapping**: Adds textures to the walls, enhancing the visual aspect of the maze.
- **Player Controls**: Supports basic player movement through the maze, allowing rotation and forward/backward movement.

## Current Issues and Work in Progress

While the project is already functional to some extent, there are a few technical issues that are actively being worked on:

### 1. **Wall Rendering Distortion**
   There is currently an issue with wall rendering, where the walls appear distorted and stretched in certain parts of the screen. This distortion could be due to incorrect field-of-view handling or improper fish-eye effect correction. I am actively investigating and refining the raycasting logic to fix this.

### 2. **Distance Calculation**
   The distance calculation for each ray is experiencing some inconsistencies. The formula for correcting the fish-eye effect seems to need more adjustment, as walls that should appear farther away are not being properly rendered at the correct height or scale.

### 3. **Texture Scaling**
   Texture stretching is another issue in the current implementation. The textures applied to the walls sometimes stretch unnaturally, leading to visual artifacts. This is likely caused by misalignment between wall slice dimensions and the scaling of textures.

## Goals for Completion

The current plan is to fix the following in the coming days:
- Fine-tune the raycasting algorithm to eliminate wall distortion.
- Correct the distance calculations and ensure all angles are handled properly.
- Ensure the textures are applied with the correct aspect ratio, improving visual clarity.
- Add more features, such as doors, items, or enemies, to make the maze more interactive.

Once these issues are resolved, the project will be feature-complete, and I look forward to seeing it fully functional soon.

## Installation

To compile and run the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/Ndunge-Makau/raycasting-maze.git
   ```
2. Install [SDL2](https://www.libsdl.org/download-2.0.php) (Simple DirectMedia Layer) for rendering.
3. Compile the project:
   ```bash
   gcc -o raycaster main.c -lSDL2 -lm
   ```
4. Run the game:
   ```bash
   ./raycaster
   ```

## Future Enhancements

- **Improved Player Controls**: Smooth player movement and look-around controls.
- **Enhanced Maze Complexity**: Larger mazes with more intricate designs.
- **Additional Game Mechanics**: Doors, keys, and interactive elements to make the game more engaging.

## Conclusion

Although the project is not yet fully complete, progress is being made steadily, and the remaining issues will be resolved soon. I am excited to see the final outcome and share the fully functional 3D maze game. Stay tuned for updates, and thank you for checking out the project!

