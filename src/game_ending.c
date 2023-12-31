/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ending.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:37:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/25 13:50:29 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_window(t_data *game)
{
	mlx_destroy_window(game->mlx_connection, game->win.mlx_win);
	game->win.mlx_win = NULL;
	return (0);
}

static void	end_mlx_connection(t_data *game)
{
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
}

int	end_game(t_data *game)
{
	if (game->win.mlx_win)
		close_window(game);
	free_map(&game->map);
	free_sprites_background(game);
	free_sprites_collectible_and_player(game);
	free_sprites_ending_and_enemy(game);
	end_mlx_connection(game);
	if (game->config_stage < 4)
		return (1);
	exit (EXIT_SUCCESS);
}

void	handle_error(int error_type, char *error_msg, t_data *game)
{
	if (game->config_stage == 2)
		free_map(&game->map);
	if (game->config_stage == 3)
		end_game(game);
	if (error_type == 1)
	{
		ft_printf("%s", error_msg);
		perror("");
		exit (EXIT_FAILURE);
	}
	ft_printf("Error\n%s", error_msg);
	exit (EXIT_FAILURE);
}
