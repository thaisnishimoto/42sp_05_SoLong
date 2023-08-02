/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/01 21:36:35 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h> //free
#include <stdio.h> //prinft
#include <X11/X.h> //keypress, mask

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

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

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char* pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

//int	render_map(t_data *data)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	while (x < WIN_WIDTH)
//	{
//		y = 0;
//		while (y < WIN_HEIGHT)
//		{
//			mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->map.ptr, x, y);
//			y++;
//		}
//		x++;
//	}
//}

void	render_rect(t_img *img, int x, int y, int color)
{
	while (x < WIN_WIDTH * 0.75)
	{
		y = WIN_HEIGHT * 0.25;
		while (y < WIN_HEIGHT * 0.75)
		{
			img_pix_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

int	render(t_data *data)
{
//	void	*img;
//	char	*relative_path = "./Space_Stars1.xpm";
//	int	img_width;
//	int	img_height;

	if (data->mlx_win != NULL)
	{
//		img = mlx_xpm_file_to_image(data->mlx_connection, relative_path, &img_width, &img_height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->map.ptr, 0, 0);
//		render_rect(&data->img, WIN_WIDTH * 0.25, WIN_HEIGHT * 0.25, 0xFF);
//		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img.mlx_img, 0, 0);
    	}
	return (0);
}

int	x_win(t_data *data)
{
        mlx_destroy_window(data->mlx_connection, data->mlx_win);
        data->mlx_win = NULL;
	return (0);
}

int	esc_win(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
        	mlx_destroy_window(data->mlx_connection, data->mlx_win);
        	data->mlx_win = NULL;
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.map.relative_path = "./Space_Stars1.xpm";
	data.mlx_connection = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT, "SO LONG");
	data.map.ptr = mlx_xpm_file_to_image(data.mlx_connection, data.map.relative_path, &data.map.width, &data.map.height);
//	data.img.mlx_img = mlx_new_image(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT);
//	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	/*Hooks*/
	mlx_loop_hook(data.mlx_connection, &render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &esc_win, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &x_win, &data);

	mlx_loop(data.mlx_connection);
	
	mlx_destroy_image(data.mlx_connection, data.map.ptr);
//	mlx_destroy_image(data.mlx_connection, data.img.mlx_img);
	mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
	return (0);
}
