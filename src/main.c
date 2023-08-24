/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/24 14:01:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	game;

	game.map.file = argv[1];
	game.config_stage = 0;
	game.ending = 0;
	read_map(argc, &game);
	validate_map_content(&game);
	check_valid_path(&game);
	initiate_game(&game);
	mlx_hook(game.win.mlx_win, DestroyNotify, StructureNotifyMask,
		&end_game, &game);
	mlx_hook(game.win.mlx_win, KeyPress, KeyPressMask, &key_hook, &game);
	mlx_loop_hook(game.mlx_connection, &render_hook, &game);
	mlx_loop(game.mlx_connection);
	return (0);
}
