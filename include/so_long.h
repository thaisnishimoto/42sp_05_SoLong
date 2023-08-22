/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 00:14:34 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h> //keypress, mask
# include "../libft/libft.h" //my libft
# include <stdio.h> //prinft
# include <stdlib.h> //malloc, free
# include <unistd.h> //write, read
# include <fcntl.h> //open, close


/*Macros*/

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef DELAY_FRAME
#  define DELAY_FRAME 100
# endif

/*Sprites*/
# define SPACE1 "./images/space_frame1.xpm"
# define SPACE2 "./images/space_frame2.xpm"
# define SPACE3 "./images/space_frame3.xpm"
# define SPACE4 "./images/space_frame4.xpm"
# define ASTEROID "./images/asteroid.xpm"
# define PORTAL "./images/portal transcendence.xpm"
# define OXYGEN "./images/oxygen.xpm"
# define ASTRO_U "./images/astronaut_up.xpm"
# define ASTRO_R "./images/astronaut_right.xpm"
# define ASTRO_L "./images/astronaut_left.xpm"
# define ASTRO_D "./images/astronaut_down.xpm"

/*Structs*/
typedef struct	s_map
{
	char	*file;
	int	columns;
	int	rows;
	char	**grid;
	int	player_count;
	int	collect_count;
	int	exit_count;
	int	valid_path;
}	t_map;

typedef struct s_dir
{
	int	x[4];
	int	y[4];
}	t_dir;

typedef struct	s_win
{
	void	*mlx_win;
	int	width;
	int	height;
}	t_win;

typedef struct	s_sprite
{
	void	*ptr;
	char	*path;
	int	width;
	int	height;
	int	x;
	int	y;
}	t_sprite;

typedef struct	s_player
{
	void	*u_ptr;
	void	*d_ptr;
	void	*r_ptr;
	void	*l_ptr;
	int	width;
	int	height;
	int	x;
	int	y;
	int	direction;
	int	move_count;
}	t_player;

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len; /*in bytes*/
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_connection;
	t_win	win;
	t_img	img;
	t_map	map;
	t_sprite	space1;
	t_sprite	space2;
	t_sprite	space3;
	t_sprite	space4;
	t_sprite	asteroid;
	t_sprite	portal;
	t_sprite	oxygen;
	t_player	astronaut;
}	t_data;

/*Main function calls*/
void	read_map(int argc, t_map *map);
void	validate_map_content(t_data *game);
void	check_valid_path(t_data *game);
void	initiate_game(t_data *game);

/*Utils - Render functions*/
int	render_map(t_data *data);
int	key_hook(int keysym, t_data *game);
//void	img_pix_put(t_img *img, int x, int y, int color);
int	render_space(t_data *data, int pos_x, int pos_y);
void	move_up(t_data *game, t_player *astronaut);
void	move_down(t_data *game, t_player *astronaut);
void	move_right(t_data *game, t_player *astronaut);
void	move_left(t_data *game, t_player *astronaut);

/*Close window functions*/
void	handle_error(int stage, int perror, char *error_msg, t_data *game);
void	free_map(t_map *map);
void	free_sprites(t_data *game);
int	close_window(t_data *game);
void	end_mlx_connection(t_data *game);
//int	esc_win(int keysym, t_data *data);

#endif
