/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 10:40:26 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map.file = argv[1];
	read_map(argc, &data.map);
	validate_map_content(&data);
	check_valid_path(&data);
	initiate_game(&data);
	mlx_hook(data.win.mlx_win, DestroyNotify, StructureNotifyMask,
		&close_window, &data);
	mlx_hook(data.win.mlx_win, KeyPress, KeyPressMask, &key_hook, &data);
	mlx_loop_hook(data.mlx_connection, &render_hook, &data);
	mlx_loop(data.mlx_connection);
	free_map(&data.map);
	free_sprites_background(&data);
	free_sprites_items(&data);
	free_sprites_player(&data);
	end_mlx_connection(&data);
	return (0);
}
