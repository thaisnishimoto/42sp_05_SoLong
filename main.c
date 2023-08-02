/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/02 15:28:56 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char* pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	render_rect(t_img *img, int color)
{
	int	x;
	int	y;

	x = WIN_WIDTH * 0.25;
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

int	render_next_frame(t_data *data)
{
	static int	i;

	if (data->mlx_win == NULL)
		return (1);
	if (i >= 0 & i <= DELAY_FRAME * 5)
		render_rect(&data->img, 0xFF0000);
	if (i > DELAY_FRAME * 5 && i <= DELAY_FRAME * 10)
		render_rect(&data->img, 0x00FF00);
	if (i > DELAY_FRAME * 10 && i <= DELAY_FRAME * 15)
		render_rect(&data->img, 0xFF);
	if (i > DELAY_FRAME * 15)
		i = 0;
	mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img.mlx_img, 0, 0);
	i++;
	return (0);
}

int	render_space(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (data->mlx_win != NULL)
	{
		while (y * 64 < WIN_HEIGHT)
		{
			x = 0;
			while (x * 64 < WIN_WIDTH)
			{
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->map.ptr, x * 64, y * 64);
				x++;
			}
			y++;
		}
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

	data.map.relative_path = "./texture_space.xpm";
	data.mlx_connection = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT, "SO LONG");
	data.map.ptr = mlx_xpm_file_to_image(data.mlx_connection, data.map.relative_path, &data.map.width, &data.map.height);
	data.img.mlx_img = mlx_new_image(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	/*Hooks*/
//	mlx_loop_hook(data.mlx_connection, &render_space, &data); //background
	mlx_loop_hook(data.mlx_connection, &render_next_frame, &data); // animation
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &esc_win, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &x_win, &data);

	mlx_loop(data.mlx_connection);
	
	mlx_destroy_image(data.mlx_connection, data.map.ptr);
//	mlx_destroy_image(data.mlx_connection, data.img.mlx_img);
	mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
	return (0);
}
