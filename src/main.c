/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/21 16:55:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char* pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

//int	render_sqr(t_img *img, int color)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	while (x < 64)
//	{
//		y = 0;
//		while (y < 64)
//		{
//			img_pix_put(img, x, y, color);
//			y++;
//		}
//		x++;
//	}
//	return (0);
//}

int	render_astronaut(t_data *data)
{
	if (data->win.mlx_win == NULL)
		return (1);
	if (data->astronaut.direction == 'r')
		mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->astronaut.r_ptr, data->astronaut.x * 64, data->astronaut.y * 64);
	return (0);
}

int	render_space(t_data *data, int pos_x, int pos_y)
{
	static int	i;

	if (i >= 0 && i <= DELAY_FRAME * 5)
      		mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->space1.ptr, pos_x * TILE_SIZE, pos_y * TILE_SIZE);
	if (i > DELAY_FRAME * 5 && i <= DELAY_FRAME * 10)
		mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->space2.ptr, pos_x * TILE_SIZE, pos_y * TILE_SIZE);
	if (i > DELAY_FRAME * 10 && i <= DELAY_FRAME * 15)
		mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->space3.ptr, pos_x * TILE_SIZE, pos_y * TILE_SIZE);
	if (i > DELAY_FRAME * 15 && i <= DELAY_FRAME * 20)
		mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->space4.ptr, pos_x * TILE_SIZE, pos_y * TILE_SIZE);
	if (i > DELAY_FRAME * 20)
		i = 0;
	i++;
	return (0);
}

void	render_collectible(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->oxygen.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

int	x_win(t_data *data)
{
        mlx_destroy_window(data->mlx_connection, data->win.mlx_win);
        data->win.mlx_win = NULL;
	return (0);
}

int	key_hook(int keysym, t_data *game)
{
	if (keysym == XK_Up || keysym == XK_w)
		move_up(game, &game->astronaut);
	if (keysym == XK_Down || keysym == XK_s)
		move_down(game, &game->astronaut);
	if (keysym == XK_Right || keysym == XK_d)
		move_right(game, &game->astronaut);
	if (keysym == XK_Left || keysym == XK_a)
		move_left(game, &game->astronaut);
	if (keysym == XK_Escape)
		x_win(game);
	return (0);
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	if (data->win.mlx_win == NULL)
		return (1);
	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.columns)
		{
			if (data->map.grid[y][x] == '0')
				render_space(data, x, y);
			if (data->map.grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->asteroid.ptr, x * 64, y * 64);
			if (data->map.grid[y][x] == 'C')
				render_collectible(data, x, y);
			if (data->map.grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->portal.ptr, x * 64, y * 64);
			if (data->map.grid[y][x] == 'P')
			{
				data->astronaut.x = x;
				data->astronaut.y = y;
				if (data->astronaut.direction == 'u')
					mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->astronaut.u_ptr, x * TILE_SIZE, y * TILE_SIZE);
				if (data->astronaut.direction == 'd')
					mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->astronaut.d_ptr, x * TILE_SIZE, y * TILE_SIZE);
				if (data->astronaut.direction == 'r')
					mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->astronaut.r_ptr, x * TILE_SIZE, y * TILE_SIZE);
				if (data->astronaut.direction == 'l')
					mlx_put_image_to_window(data->mlx_connection, data->win.mlx_win, data->astronaut.l_ptr, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	t_data	data;
	
	data.map.file = argv[1];
	read_map(argc, &data.map);
	validate_map_content(&data.map);
	check_valid_path(&data);
	initiate_game(&data);
//	data.img.mlx_img = mlx_new_image(data.mlx_connection, 64, 64);
//	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	/*Hooks*/
	mlx_hook(data.win.mlx_win, KeyPress, KeyPressMask, &key_hook, &data);
	mlx_hook(data.win.mlx_win, DestroyNotify, StructureNotifyMask, &x_win, &data);
	mlx_loop_hook(data.mlx_connection, &render_map, &data);

	mlx_loop(data.mlx_connection);
	
	free_map(&data.map);
	mlx_destroy_image(data.mlx_connection, data.space1.ptr);
	mlx_destroy_image(data.mlx_connection, data.space2.ptr);
	mlx_destroy_image(data.mlx_connection, data.space3.ptr);
	mlx_destroy_image(data.mlx_connection, data.space4.ptr);
	mlx_destroy_image(data.mlx_connection, data.asteroid.ptr);
	mlx_destroy_image(data.mlx_connection, data.oxygen.ptr);
	mlx_destroy_image(data.mlx_connection, data.portal.ptr);
	mlx_destroy_image(data.mlx_connection, data.astronaut.u_ptr);
	mlx_destroy_image(data.mlx_connection, data.astronaut.d_ptr);
	mlx_destroy_image(data.mlx_connection, data.astronaut.r_ptr);
	mlx_destroy_image(data.mlx_connection, data.astronaut.l_ptr);
//	mlx_destroy_image(data.mlx_connection, data.img.mlx_img);
	mlx_destroy_display(data.mlx_connection);
	free(data.mlx_connection);
	return (0);
}
