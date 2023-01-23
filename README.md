# ! README IN PROGRESSION !

# CUB3D
This project's goal is to create a 3D graphical reprensentation of the inside of a maze in a 2D game.<br />
This is one of the projects of the 42 common core.

## Prerequisites

I have done this project on a Linux VM, so if you want to have the best conditions to use this program, I suggest to use it in a Linux environment.

## How to launch a game

To use the program, first of all, you need to compile it with the following command :
```bash
  make
```
Thereby, you will have an executable named `cub3D`.<br />
Now, you need to select a map that you want to explore in the `cub3d_maps` folder :
![listofmaps](https://user-images.githubusercontent.com/51683861/214024457-55c51905-bfdd-4bc4-aa03-39eb7f17d28a.png)<br />
Once you have chosen a map, type the following command to start a game :
```bash
./cub3D cub3d_maps/the_map_you_have_chosen.cub
```

## How to play a game
Once the game is launched, a window will pop up.<br />
It will look something like this :
![unnamed](https://user-images.githubusercontent.com/51683861/214078038-b1ad43c3-060a-4fcf-bec3-c30197e0278e.jpg)<br />


Use the `W`, `A`, `S` and `D` keys respectively to move **forward**, **to the left**, **backward**, and **to the right**.<br />
Use the **left arrow key** to **move the camera to the left**, and <ins>*the right arrow key*</ins> to <ins>*move it to the right*</ins>.<br />
Press `ESC` or the red cross on the window's frame to quit the game.<br />
