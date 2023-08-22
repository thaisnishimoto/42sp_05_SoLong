/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 12:19:07 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char* pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	main(int argc, char* argv[])
{
	t_data	data;
	
	data.map.file = argv[1];
	read_map(argc, &data.map);
	validate_map_content(&data);
	check_valid_path(&data);
	initiate_game(&data);
	mlx_hook(data.win.mlx_win, KeyPress, KeyPressMask, &key_hook, &data);
	mlx_hook(data.win.mlx_win, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop_hook(data.mlx_connection, &render_hook, &data);
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
