/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:14:15 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 10:26:05 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	free_sprites_background(t_data *game)
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
	if (game->move_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->move_display.ptr);
	if (game->star_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->star_display.ptr);
}

void	free_sprites_items(t_data *game)
{
	if (game->star.ptr1 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr1);
	if (game->star.ptr2 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr2);
	if (game->star.ptr3 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr3);
	if (game->star.ptr4 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr4);
	if (game->portal.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->portal.ptr);
	if (game->block_exit.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->block_exit.ptr);
}

void	free_sprites_player(t_data *game)
{
	if (game->astronaut.u_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.u_ptr);
	if (game->astronaut.d_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.d_ptr);
	if (game->astronaut.r_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.r_ptr);
	if (game->astronaut.l_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.l_ptr);
}
