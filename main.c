/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/03 15:28:27 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char* pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_sqr(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			img_pix_put(img, x, y, color);
			y++;
		}
		x++;
	}
	return (0);
}

int	render_astronaut(t_data *data)
{
	if (data->mlx_win == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->astronaut.ptr, 64 + data->astronaut.x, 64);
	return (0);
}
//int	move_sqr(t_data *data)
//{
//	static int	i;
//
//	if (data->mlx_win == NULL)
//		return (1);
//	if (i >= 0 & i <= DELAY_FRAME * 5)
//		render_rect(&data->img, 0xFF0000);
//	if (i > DELAY_FRAME * 5 && i <= DELAY_FRAME * 10)
//		render_rect(&data->img, 0x00FF00);
//	if (i > DELAY_FRAME * 10 && i <= DELAY_FRAME * 15)
//		render_rect(&data->img, 0xFF);
//	if (i > DELAY_FRAME * 15)
//		i = 0;
//	mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img.mlx_img, 0, 0);
//	i++;
//	return (0);
//}

int	render_space(t_data *data)
{
	int	x;
	int	y;
	static int	i;

	y = 0;
	if (data->mlx_win != NULL)
	{
		while (y * 64 < WIN_HEIGHT)
		{
			x = 0;
			while (x * 64 < WIN_WIDTH)
			{
				if (i >= 0 && i <= DELAY_FRAME * 5)
      					mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->space1.ptr, x * 64, y * 64);
				if (i > DELAY_FRAME * 5 && i <= DELAY_FRAME * 10)
					mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->space2.ptr, x * 64, y * 64);
				if (i > DELAY_FRAME * 10 && i <= DELAY_FRAME * 15)
					mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->space3.ptr, x * 64, y * 64);
				if (i > DELAY_FRAME * 15 && i <= DELAY_FRAME * 20)
					mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->space4.ptr, x * 64, y * 64);
				if (i > DELAY_FRAME * 20)
					i = 0;
				i++;
				x++;
			}
			y++;
		}
    	}
	return (0);
}

int	render_asteroid(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (data->mlx_win != NULL)
	{
		while (y == 0)
		{
			x = 0;
			while (x * 64 < WIN_WIDTH)
			{
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->asteroid.ptr, x * 64, y * 64);
				x++;
			}
			y++;
		}
    	}
	return (0);
}

int     render_game(t_data *data)
{
	if (data->mlx_win == NULL)
		return (1);
	//render_sqr(&data->img, 0xFFFFFF);
	render_space(data);
	render_asteroid(data);
	render_astronaut(data);
	//mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img.mlx_img, 64, 64);
	return (0);
}

int	x_win(t_data *data)
{
        mlx_destroy_window(data->mlx_connection, data->mlx_win);
        data->mlx_win = NULL;
	return (0);
}

int	key_hook(int keysym, t_data *data)
{
	if (keysym == XK_Right)
		data->astronaut.x += TILE_SIZE;
	else if (keysym == XK_Escape)
	{
        	mlx_destroy_window(data->mlx_connection, data->mlx_win);
        	data->mlx_win = NULL;
	}
	return (0);
}

int	init_sprites(t_data* data)
{
	data->space1.ptr = mlx_xpm_file_to_image(data->mlx_connection, SPACE_PATH1, &data->space1.width, &data->space1.height);
	data->space2.ptr = mlx_xpm_file_to_image(data->mlx_connection, SPACE_PATH2, &data->space2.width, &data->space2.height);
	data->space3.ptr = mlx_xpm_file_to_image(data->mlx_connection, SPACE_PATH3, &data->space3.width, &data->space3.height);
	data->space4.ptr = mlx_xpm_file_to_image(data->mlx_connection, SPACE_PATH4, &data->space4.width, &data->space4.height);
	data->asteroid.ptr = mlx_xpm_file_to_image(data->mlx_connection, ASTEROID_PATH, &data->asteroid.width, &data->asteroid.height);
	data->astronaut.ptr = mlx_xpm_file_to_image(data->mlx_connection, ASTRONAUT_L, &data->astronaut.width, &data->astronaut.height);
	printf("size of frame1: %d x %d", data->astronaut.width, data->astronaut.height);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_connection = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT, "SO LONG");
	init_sprites(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_connection, 64, 64);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	/*Hooks*/
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &key_hook, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &x_win, &data);
	mlx_loop_hook(data.mlx_connection, &render_game, &data);

	mlx_loop(data.mlx_connection);
	
	mlx_destroy_image(data.mlx_connection, data.space1.ptr);
	mlx_destroy_image(data.mlx_connection, data.space2.ptr);
	mlx_destroy_image(data.mlx_connection, data.space3.ptr);
	mlx_destroy_image(data.mlx_connection, data.space4.ptr);
	mlx_destroy_image(data.mlx_connection, data.asteroid.ptr);
	mlx_destroy_image(data.mlx_connection, data.astronaut.ptr);
	mlx_destroy_image(data.mlx_connection, data.img.mlx_img);
	mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
	return (0);
}
