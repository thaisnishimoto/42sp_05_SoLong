/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_end_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:37:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 19:27:49 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_error(int stage, int error_type, char *error_msg, t_data *game)
{
	if (stage >= 2)
	{
		free_map(&game->map);
		if (stage == 3)
		{
			free_sprites(game);
			end_mlx_connection(game);
		}
	}
	if (error_type == 1)
	{
		ft_printf("%s", error_msg);
		perror("");
		exit (1);
	}
	ft_printf("Error\n%s", error_msg);
	exit (1);
}

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
}

void	free_sprites(t_data *game)
{
	if (game->space1.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->space1.ptr);
	if (game->space2.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->space2.ptr);
	if (game->space3.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->space3.ptr);
	if (game->space4.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->space4.ptr);
	if (game->asteroid.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->asteroid.ptr);
	if (game->oxygen.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->oxygen.ptr);
	if (game->portal.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->portal.ptr);
	if (game->block_exit.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->block_exit.ptr);
	if (game->astronaut.u_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.u_ptr);
	if (game->astronaut.d_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.d_ptr);
	if (game->astronaut.r_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.r_ptr);
	if (game->astronaut.l_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.l_ptr);
	if (game->move_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->move_display.ptr);
	if (game->tank_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->tank_display.ptr);
}

int	close_window(t_data *game)
{
	mlx_destroy_window(game->mlx_connection, game->win.mlx_win);
	game->win.mlx_win = NULL;
	return (0);
}

void	end_mlx_connection(t_data *game)
{
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
}
