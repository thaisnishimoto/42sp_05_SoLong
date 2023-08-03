/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/03 15:03:36 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h> //free
# include <stdio.h> //prinft
# include <X11/X.h> //keypress, mask

/*Macros*/
# ifndef WIN_WIDTH
#  define WIN_WIDTH 800
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 600
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef DELAY_FRAME
#  define DELAY_FRAME 150
# endif

/*Sprites*/
# define SPACE_PATH1 "./images/space_frame1.xpm"
# define SPACE_PATH2 "./images/space_frame2.xpm"
# define SPACE_PATH3 "./images/space_frame3.xpm"
# define SPACE_PATH4 "./images/space_frame4.xpm"
# define ASTEROID_PATH "./images/asteroid_64.xpm"
# define ASTRONAUT_U "./images/astronaut_back.xpm"
# define ASTRONAUT_R "./images/astronaut_right.xpm"
# define ASTRONAUT_L "./images/astronaut_left.xpm"
# define ASTRONAUT_D "./images/astronaut_front.xpm"

/*Structs*/
typedef struct	s_sprite
{
	void	*ptr;
	char	*path;
	int	width;
	int	height;
	int	x;
	int	y;
}	t_sprite;

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
	void	*mlx_win;
	t_img	img;
	t_sprite	space1;
	t_sprite	space2;
	t_sprite	space3;
	t_sprite	space4;
	t_sprite	asteroid;
	t_sprite	astronaut;
}	t_data;

/*Render functions*/
void	render_rect(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int	render_space(t_data *data);

/*Close window functions*/
int	x_win(t_data *data);
int	esc_win(int keysym, t_data *data);

#endif
