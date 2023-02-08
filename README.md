# CUB3D
This project's goal is to create a 3D graphical representation of the inside of a maze, in a 2D game that you play as a first-person player.<br />

In order to do that, we have to use the [ray casting](https://en.wikipedia.org/wiki/Ray_casting) technique.<br />
Ray casting consists of casting imaginary rays, which are actually Euclidean [vectors](https://en.wikipedia.org/wiki/Vector_(mathematics_and_physics)) which go from the point of the player to a point from a wall.<br />
The distance between those points is used to calculate the distance between the player and the walls and to draw them accordingly.<br />

This project is part of the 42 school common core curriculum.

# What this project brought me

With this project, I have learned to use the `minilibix` library to have images, textures, and colored pixels.<br />
I have improved my skills in the C language :
- I used structures to move multiple data in my code,
- I used the `double` and `float` types to manipulate radians,
- I have learned to organize my code better when it comes to a big project : multiple folders to sort my files coherently, a few functions per file,...
- I have learned to parse the input data to check errors and to be sure it respects strict rules for the program to work properly,

And I learned trigonometry again in order to understand and apply the right algorithm to use the ray casting.

## Prerequisites

I have done this project on a Linux VM, so if you want to have the best conditions to use this program, I suggest to use it in a Linux environment.<br />

You need to have a **QWERTY** keyboard in order to use the program properly.<br />
If you have an AZERTY keyboard, you can switch to QWERTY using the following command as root (on Linux) :
```bash
setxkbmap us
```
To switch back to AZERTY :
```bash
setxkbmap fr
```

## How to launch a game

To use the program, first of all, you need to compile it with the following command :
```bash
  make
```
Thereby, you will have an executable named `cub3D`.<br />
Now, you need to select a map that you want to explore in the `cub3d_maps` folder :
![listofmaps](https://user-images.githubusercontent.com/51683861/214024457-55c51905-bfdd-4bc4-aa03-39eb7f17d28a.png)<br />
Once you chose a map, type the following command to start a game :
```bash
./cub3D cub3d_maps/the_map_you_chose.cub
```
 P.S. : Some of the maps don't work because they don't respect the conditions of a valid file. I needed them to test my parsing and my error messages.

## How to play a game
Once the game is launched, a window will pop up.<br />
It will look something like this :
![unnamed](https://user-images.githubusercontent.com/51683861/214078038-b1ad43c3-060a-4fcf-bec3-c30197e0278e.jpg)<br />


Use the `W`, `A`, `S` and `D` keys respectively to move **forward**, **to the left**, **backward**, and **to the right**.<br />
If you have switched your AZERTY keyboard to QWERTY, use the `Z` key to **move forward**, and the `Q` key to **move to the left**.<br />
The rest of the keys remains the same.<br />

Use the **left arrow key** to **move the camera to the left**, and <ins>*the right arrow key*</ins> to <ins>*move it to the right*</ins>.<br />

Press `ESC` or the red cross on the window's frame to quit the game.<br />
