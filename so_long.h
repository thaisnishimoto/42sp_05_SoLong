/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/02 15:21:42 by tmina-ni         ###   ########.fr       */
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
#  define DELAY_FRAME 10
# endif

/*Structs*/
typedef struct	s_map
{
	void	*ptr;
	char	*relative_path;
	int	width;
	int	height;
}	t_map;

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
	t_map	map;
}	t_data;

/*Render functions*/
void	render_rect(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int	render_space(t_data *data);

/*Close window functions*/
int	x_win(t_data *data);
int	esc_win(int keysym, t_data *data);

#endif
