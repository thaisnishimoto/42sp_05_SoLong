/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/24 14:45:01 by tmina-ni         ###   ########.fr       */
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

# ifndef REPEAT_FRAME
#  define REPEAT_FRAME 90
# endif

/*Sprites*/
# define SPACE1 "./images/space_frame1.xpm"
# define SPACE2 "./images/space_frame2.xpm"
# define SPACE3 "./images/space_frame3.xpm"
# define SPACE4 "./images/space_frame4.xpm"
# define ASTEROID "./images/asteroid.xpm"
# define PORTAL "./images/portal.xpm"
# define BLOCK_E "./images/blocked_exit.xpm"
# define STAR1 "./images/star1.xpm"
# define STAR2 "./images/star2.xpm"
# define STAR3 "./images/star3.xpm"
# define STAR4 "./images/star4.xpm"
# define ASTRO_U "./images/astronaut_up.xpm"
# define ASTRO_R "./images/astronaut_right.xpm"
# define ASTRO_L "./images/astronaut_left.xpm"
# define ASTRO_D "./images/astronaut_down.xpm"
# define MOVES "./images/moves_display.xpm"
# define COLLEC "./images/star_display.xpm"
# define HOLE1 "./images/black_hole_s.xpm"
# define HOLE2 "./images/black_hole_m.xpm"
# define HOLE3 "./images/black_hole_b.xpm"
# define HOLE4 "./images/black_hole_lose.xpm"
# define GOVER "./images/game_over.xpm"

/*Structs*/
typedef struct s_map
{
	char	*file;
	char	**grid;
	int		columns;
	int		rows;
	int		player_count;
	int		collect_count;
	int		exit_count;
	int		valid_path;
}	t_map;

typedef struct s_dir
{
	int	x[4];
	int	y[4];
}	t_dir;

typedef struct s_win
{
	void	*mlx_win;
	int		width;
	int		height;
}	t_win;

typedef struct s_sprite
{
	void	*ptr;
	char	*path;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_animate
{
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;
	int		width;
	int		height;
}	t_animate;

typedef struct s_player
{
	void	*u_ptr;
	void	*d_ptr;
	void	*r_ptr;
	void	*l_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		direction;
	int		move_count;
}	t_player;

typedef struct s_data
{
	void		*mlx_connection;
	t_win		win;
	int			config_stage;
	int			ending;
	t_map		map;
	t_animate	space;
	t_animate	star;
	t_player	astronaut;
	t_sprite	asteroid;
	t_sprite	portal;
	t_sprite	block_exit;
	t_sprite	move_display;
	t_sprite	star_display;
	t_animate	hole;
	t_sprite	game_over;
}	t_data;

/*Main function calls*/
void	read_map(int argc, t_data *game);
void	validate_map_content(t_data *game);
void	check_valid_path(t_data *game);
void	initiate_game(t_data *game);

/*Hook events*/
int		key_hook(int keysym, t_data *game);
int		render_hook(t_data *game);
void	render_game(t_data *game, int x, int y);

/*Utils - Render functions*/
void	render_space(t_data *game, int x, int y);
void	render_wall(t_data *game, int x, int y);
void	render_collectible(t_data *game, int x, int y);
void	render_astronaut(t_data *game, int x, int y);
void	render_black_hole(t_data *game, int x, int y);
void	display_on_screen(t_data *game);

/*Utils - Move functions*/
void	move_up(t_data *game, t_player *astronaut);
void	move_down(t_data *game, t_player *astronaut);
void	move_right(t_data *game, t_player *astronaut);
void	move_left(t_data *game, t_player *astronaut);

/*Utils - Free functions*/
void	free_map(t_map *map);
void	free_sprites_background(t_data *game);
void	free_sprites_items(t_data *game);
void	free_sprites_player(t_data *game);
int		end_game(t_data *game);

/*Close window functions*/
void	handle_error(int perror, char *error_msg, t_data *game);

#endif
