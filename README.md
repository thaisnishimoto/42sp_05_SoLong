<p align="center">
  <img src="https://github.com/thaisnishimoto/42-project-badges/blob/main/badges/so_longm.png" alt="SoLong bonus"/>
</p>

<h1 align=center>
	<b>So Long</b>
</h1>

<p align="center"><i>"This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements."</i></p>  

![so_long_cover](https://github.com/thaisnishimoto/42sp_05_SoLong/assets/126536908/d04e988c-c832-425d-9aff-63c9a4b56857)

<h2>
 Status
</h2>

Finished: ___<br>
Grade: ___/100

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
### Game commands:

### To create a valid map, it must:
- be in format *.ber
- be rectangular
- be surrounded by walls
- have a valid path to the exit and collectibles
- contain only these 6 characters:
'0' for empty space
1 for wall
C for collectible (at least one)
E for map exit (one only)
P for player’s starting position (one only)
H for enemy

<h2>
You Win - example:
</h2>

<h2>
Game Over - example:
</h2>

<h2>
Minilibx
</h2>

Linux can be managed through the command line interface. However, most end users prefere using a graphical user interface (GUI).<br>

The X Window System is a portable, network-based display system. It provides the foundation to building a GUI and consists of two major pieces of software: a server which accepts requests to do things to a display and the low-level C library called Xlib.

It allows to run applications on windows, move windows around the screen and click on items.

- The X Server is executed in the local machine and is responsible for graphically drawing windows on the screen, as well as managing the keyboard and mouse.
- Xlib is the library that programs use to interact with the X Server, providing functions for creating windows, handling events, drawing graphics, and managing input devices. Programs written with Xlib functions are called clients.
- The X Clients are applications that connect to the X Server, remote or locally, and make requests for it . They access and use display resources. Each application looks different, because X does not impose any policy on how the GUI should operate.  
- The Window Manager customize how the windows look, behave and stack along with each other. It is a component of a desktop environment, but can be used alone. It cames barebone, which allows for customization and flexibility. It is just another client using Xlib which can contact and interact with a running X server.
- The Desktop Environment (optional) adds tools and utilities such as start menu, taskbar, icons, screen locker, etc. It dictates how the GUI looks.

MiniLibX is a library based on Xlib, which contains functions for interacting with an X server. It is meant for beginners to learn the basics of graphics development.
https://www.aconvert.com/image/#google_vignette
https://elliotjermy.itch.io/up940183-meteor-defence
