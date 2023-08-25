/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:14:15 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/25 00:33:15 by tmina-ni         ###   ########.fr       */
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
	if (game->space.ptr1 != NULL)
		mlx_destroy_image(game->mlx_connection, game->space.ptr1);
	if (game->space.ptr2 != NULL)
		mlx_destroy_image(game->mlx_connection, game->space.ptr2);
	if (game->space.ptr3 != NULL)
		mlx_destroy_image(game->mlx_connection, game->space.ptr3);
	if (game->space.ptr4 != NULL)
		mlx_destroy_image(game->mlx_connection, game->space.ptr4);
	if (game->asteroid.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->asteroid.ptr);
	if (game->portal.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->portal.ptr);
	if (game->move_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->move_display.ptr);
	if (game->star_display.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->star_display.ptr);
}

void	free_sprites_collectible_and_player(t_data *game)
{
	if (game->star.ptr1 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr1);
	if (game->star.ptr2 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr2);
	if (game->star.ptr3 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr3);
	if (game->star.ptr4 != NULL)
		mlx_destroy_image(game->mlx_connection, game->star.ptr4);
	if (game->astronaut.u_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.u_ptr);
	if (game->astronaut.d_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.d_ptr);
	if (game->astronaut.r_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.r_ptr);
	if (game->astronaut.l_ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->astronaut.l_ptr);
}

void	free_sprites_ending_and_enemy(t_data *game)
{
	if (game->you_win.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->you_win.ptr);
	if (game->win_portal.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->win_portal.ptr);
	if (game->game_over.ptr != NULL)
		mlx_destroy_image(game->mlx_connection, game->game_over.ptr);
	if (game->hole.ptr1 != NULL)
		mlx_destroy_image(game->mlx_connection, game->hole.ptr1);
	if (game->hole.ptr2 != NULL)
		mlx_destroy_image(game->mlx_connection, game->hole.ptr2);
	if (game->hole.ptr3 != NULL)
		mlx_destroy_image(game->mlx_connection, game->hole.ptr3);
	if (game->lose_hole.ptr1 != NULL)
		mlx_destroy_image(game->mlx_connection, game->lose_hole.ptr1);
	if (game->lose_hole.ptr2 != NULL)
		mlx_destroy_image(game->mlx_connection, game->lose_hole.ptr2);
	if (game->lose_hole.ptr3 != NULL)
		mlx_destroy_image(game->mlx_connection, game->lose_hole.ptr3);
}
