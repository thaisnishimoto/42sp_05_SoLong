<p align="center">
  <img src="https://github.com/thaisnishimoto/42-project-badges/blob/main/badges/so_longm.png" alt="SoLong bonus"/>
</p>

<h1 align=center>
	<b>So Long</b>
</h1>

<p align="center"><i>"This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements."</i></p>  

<h2>
 Status
</h2>

**Finished:**  2023, August 25th <br>
**Grade:** 125/100

<h2>
Installation
</h2>

1. Clone the repository
```sh
git clone git@github.com:thaisnishimoto/42sp_05_SoLong.git
```

2. Compile the game
```sh
make
```

3. Run the game with the a map file from the maps directory 
```sh
make run MAP=<map_filename.ber>
```

<h2>
Usage
</h2>

The goal is to collect all stars on the map and exit through the portal.

### Game commands:
|       KEY        |          ACTION         |
|:----------------:|:-----------------------:|
|     `W` , `↑`    |         Move up         |
|     `A` , `←`    |        Move left        |
|     `S` , `↓`    |        Move down        |
|     `D` , `→`    |        Move right       |
|`ESC` , `X button`|       Close window      |

### To create a valid map, it must:
- be rectangular
- be surrounded by walls
- have a valid path to the exit and collectibles
- contain only these 6 characters:
  - 0 for an empty space
  - 1 for a wall
  - C for a collectible (at least one)
  - E for a map exit (one only)
  - P for the player’s starting position (one only)
  - H for enemy (optional)

<h2>
You Win - demo:
</h2>

![gif_win_game](https://github.com/thaisnishimoto/42sp_05_SoLong/assets/126536908/e3b9fadf-d2ff-49de-b23a-d6d062295a3d)

<h2>
Game Over - demo:
</h2>

![gif_lose_game](https://github.com/thaisnishimoto/42sp_05_SoLong/assets/126536908/d4275f5f-84cd-409d-8d1d-5ae7ae9145ed)

<h2>
Minilibx
</h2>

MiniLibX is a library based on Xlib, which contains functions for interacting with an X server. It is meant for beginners to learn the basics of graphics development.
It allows to run applications on windows, move windows around the screen and click on items.
