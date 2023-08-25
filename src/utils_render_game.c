/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:12:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/25 00:15:25 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_space(t_data *game, int x, int y)
{
	static int	i;

	if (i >= 0 && i <= REPEAT_FRAME * 5)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space.ptr1, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 5 && i <= REPEAT_FRAME * 10)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 10 && i <= REPEAT_FRAME * 15)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space.ptr3, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 15 && i <= REPEAT_FRAME * 20)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space.ptr4, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 20)
		i = 0;
	i++;
}

void	render_wall(t_data *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->move_display.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (x == 0 && y == 1)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->star_display.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->asteroid.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_collectible(t_data *game, int x, int y)
{
	static int	i;

	if (i >= 0 && i <= REPEAT_FRAME * 1)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->star.ptr1, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 1 && i <= REPEAT_FRAME * 2)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->star.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 2 && i <= REPEAT_FRAME * 3)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->star.ptr3, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 3 && i <= REPEAT_FRAME * 4)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->star.ptr4, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 4)
		i = 0;
	i++;
}

void	render_astronaut(t_data *game, int x, int y)
{
	game->astronaut.x = x;
	game->astronaut.y = y;
	if (game->astronaut.direction == 'u')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->astronaut.u_ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->astronaut.direction == 'd')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->astronaut.d_ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->astronaut.direction == 'r')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->astronaut.r_ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->astronaut.direction == 'l')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->astronaut.l_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_exit(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
		game->portal.ptr, x * TILE_SIZE, y * TILE_SIZE);
}
