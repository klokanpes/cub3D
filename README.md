_This project has been created as part of the 42 curriculum by <vcerny>[, <fnagy>]._

# 🧱 cub3D
![screenshot of runtime](https://github.com/klokanpes/cub3D/blob/main/cub3d_img.jpg?raw=true)


# 📌 Description
This is a raycaster "game" implementing algorithms similar to the famous Wolfenstein3D. This implementation contains:
* A raycasting algorithm
* Wall colisions with the ability to slide along walls
* A minimap
* and fps counter
* movement via WSAD and left/right arrows for turning


## 🧑🏻‍💻 Function of the application
The following text describes the basic functional logic of this program.
### 🎯 Input validation
On startup, the data from the .cub file has to be validated. This is done through recursive reading of the map file and following checks.

The game contains one main struct that holds all of the states and data.

All pointer fields of this struct are initially initialized to NULL, so that during checks (and especially on error, allocated memory can be easily freed without touching not yet allocated stuff).

The texture files are sanitized and checked for existence via open() - else minilibx segfaults when trying to load non existent texture, map is normalized, checked for borders -> both via neighbour check and diagonal check, all data fields that should be read are also checked for existence (colors...) and values.

Color values are extracted via ft_atoi and ft_split, and then bitshifted into position inside a uint32_t.

### 🎯 Image creation
The images are then loaded via minilibx's mlx_xpm_file_to_image() into an image form so that they can be worked with later.

Minimap textures are created the same way, although their names are hardcoded in the cub3d.h header file.
To change the minimap tile size/texture size effectively, minilibx has to load a bigger image, but the size has to be changed as well, and it has to correspond the actual image size!

### 🎯 Minimap build
The minimaps(graphical) is built on startup in its entirety using the combination ((map_width * minimap_texture_width) * (map_height * minimap_texture_height)) for its buffer size. Then, within a double loop effectively, all pixels are copied from the texture images to the minimap large image. This is done via ft_memcpy row by row.

This all encompassing minimap is then used on each frame to generate the miniature minimap image.

### 🎯 Game loop
The game loop contains multiple elements. Except for the further mentioned ones, one of the main logic necessities of the game loop is keeping track of time_delta between frames. That makes the game run at a constant speed withoud regard for the actual framerate. Time_delta is computed on each frame (meaning on each itteration of the game loop), and this value then multiplace the movement speed constants so that the player movement speed stays the same, be it 10 FPS or 200 FPS

#### 🧩 Update position
The position is updated on each itteration of the game loop based on whether any of WSAD keys are currently being pressed. Simultaneous push of opposing buttons has no effect.

The complete position change is all agregated into a new position (a compund of time_delta, movement speed constant, buttons pressed and their combinations) - to avoid faster diagonal movement, the intended step is normalized, and then the new position is checked for colisions. The player is being treated as a circle with a non-zero radius for this check which makes him not get stuck within inside corners and also not be able to clip through outside corners (in effect this is done via checking the colisions not at the player position but at two points 90 degrees apart related to the player and player perpendicular vector.)

Lastly, since the new position is a complement of x and y coordinates they are being tested and applied independently. Ideally, that results in a clean movement within empty space. But also, if one of the two would result in a colision but the other would not, only the colision free change is applied. This makes the player character be able to slide along walls without any "physics"...

#### 🧩 Update rotation
The vector is updated on each itteration of the game loop based on whether any of left/right arrow is being pressed. Simultaneous press of both buttons at the same time has no effect.

Firsly the original vector is noted so that if nothing is pressed we still have a value. Then the angular velocity is computed (delta_theta = rotational speed constant * time delta)

Then the direction is computed with sinus and cosinus functions and a new plane (player perpendicular vector is set).

#### 🧩 Raycasting
This is the most important part of the project, the raycasting algorithm...

In this implementation it has seven parts basically. The first one just gets some data through minilibs (like img addressess, endians, ...), then everything runs in a loop.

The viewport here is hardcoded to 1280 by 720 pixels, which means that the raycasting algorithm runs for every single column of pixels that are being drawn to the image buffer. Meaning 1280 times per frame.

##### 🤌🏻 ft_raycast_set_vals_in_loop
Sets up initial values:
* camera_x (a perpendicular vector to the player vector) which affects the FOV by its length
* ray directon (x and y)
* map coordinates transformed to ints (char ** map position)
* delta_distance is the initial distance the ray has to travel to the next boundary (next block), then within the code it gets incremented by step
* hit is a hit flag for colision

##### 🤌🏻 ft_raycast_set_step_x_n_y
Step_x and y are directions. But not in the sense of the ray but in the ddm algorithm. They are directions where to move in the map space. Not sure what you mean by side_x and y. There is an int side which keeps track of the movement in the collision algorithm ddm and based on that I know which was the last movement that occured before a collision. Therefore that differentitates which face of the wall was hit. So combined with the step, x and y, I can differentiate N/S/E/W walls and therefore textures

##### 🤌🏻 ft_raycast_dda
DDA (digital differential analysis) is an algorithm typically used on square grids to find which squares a line hits (for example to draw a line on a screen, which is a grid of square pixels). So we can also use it to find which squares of the map our ray hits, and stop the algorithm once a square that is a wall is hit.

This algorithm jumps exactly one square each loop, either a square in the x-direction, or a square in the y-direction. If it has to go in the negative or positive x-direction, and the negative or positive y-direction will depend on the direction of the ray, and this fact will be stored in stepX and stepY.

When a collision is detected the DDA loop ends and we move on...

##### 🤌🏻 ft_raycast_colision_vals
Computes (most importantly) the distance to the wall and where the wall was hit. This results in draw_start and draw_end being set (where ceiling ends and floor beings -> in the middle is the actual wall texture)

##### 🤌🏻 ft_raycast_set_current_texture
Based on step (x or y) and side - which keeps track of the movement in the collision algorithm ddm and based on that I know which was the last movement that occured before a collision. Therefore that differentitates which face of the wall was hit. So combined with the step, x and y, I can differentiate N/S/E/W walls and therefore textures

##### 🤌🏻 ft_raycast_draw_column
the final part of the algorithm is drawing every pixel in each column. All is done via draw_start and end. What is above draw_start gets ceiling color, what is bellow gets floor color. In the middle, I get the appropriate pixel color based on the original texture (I know where the wall was hit and can transform that to the texture size units) and draw that.

#### 🧩 Minimap rendering
The minimap is rendered on each frame. It's position is hardcoded so that it slightly overlays the raycasted image and is in the middle.

How it works in essence is we know the player position in the game world. We can scale it to the minimap units (since we know the size of each minimap tile). The player position is therefore transformed to the minimap units, the minimap frame in the viewport is backfilled with black (to hide the what would effectively be outside), and then a square if 150 pixels from the player position to each direction is copied from the all encompassing minimap image stored in runtime memory to the viewport.

Some calculation is being done so that only valid pixel data is copied. However, when all was copied (during development), nothing segfault, it just result in white noise being on the outside of the minimap... Could be useful, not exacly pretty but not ugly at the same time - basically memory visualisation :D

Lastly, the player position is drawn as a small circle around the player transformed position pixel in the minimap. Then a short line is drawn to signify the player vector (where the player is looking).

#### 🧩 FPS counter
FPS value is injected into each frame using minilibx's mlx_string_put. The string in question is computed every 30 frames. Because of performance reasons (requires allocation) and aesthetic reasons (per frame FPS is very jittery and not nice to look at). The main t_data struct keeps track of time_delta_compound and a frame counter, every thirty frames a new value is computed and stored. It is being pushed to the window on each frame. Since the window is being cleared on every frame, no ghosting appears.

This method has a side effect that the first value only appears after the first 30 frames have already been drawn.

# ⚙️ Instructions
## Compilation
Compile simply with:
- make
During compilation, some dependencies get cloned and compiled. Therefore, before the first compilation, some dependencies in the code will be marked as missing.

Make is configured per the subject to containt:
~~~
- all
- clean
- fclean
- re
~~~

## 👉🏼 Usage
Example usage: >$ ./cub3d map_file.cub

Exit the application with ESC key when the application window is in the foreground, or simply by pressing the X button of the window

## 🗾 Valid maps
A valid map has to have the following fields in any order:
~~~
* N path_to_north_wall_texture.xpm
* S path_to_south_wall_texture.xpm
* E path_to_east_wall_texture.xpm
* W path_to_west_wall_texture.xpm
* C ceiling_color - format 255,255,255
* F floor_color - format 255,255,255
* uninterupted map with borders fully around, even diagonals. The map has to contain a player starting position that can be marked N/S/E/W
~~~

Example of a valid map:
~~~
11111
10001
10N01
10001
11111
~~~

A map like the following one would be considered invalid because it lacks borders in the corners - borders are checked via direct neighbours and diagonals:
~~~
 111
10001
10N01
10001
 111
~~~
Any other values or map contents are not supported.

# 📚 Resources
[minilibx documentation](https://harm-smits.github.io/42docs/)

[raycasting](https://lodev.org/cgtutor/raycasting.html)

majority of the currently used textures are from the original game, sourced from here: [textures: lodev.org](https://lodev.org/cgtutor/images/wolftextures.png)

[A wonderful video explainer](https://www.youtube.com/watch?v=NbSee-XM7WA)

# 🤖 AI use
AI was used in this project mainly as a tutor with whom it is possible to discuss. The authors of this project like to use AI as rubber ducks 🦆, not neccessarily helpful by it self, but better to write about issues than talking to a wall (or a rubber duck )
