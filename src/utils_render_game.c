/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:12:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 12:18:01 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_space(t_data *game, int x, int y)
{
	static int	i;

	if (i >= 0 && i <= REPEAT_FRAME * 5)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space1.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 5 && i <= REPEAT_FRAME * 10)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space2.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 10 && i <= REPEAT_FRAME * 15)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space3.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 15 && i <= REPEAT_FRAME * 20)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->space4.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 20)
		i = 0;
	i++;
}

static void	render_wall(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
		game->asteroid.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_collectible(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
		game->oxygen.ptr, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_astronaut(t_data *game, int x, int y)
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

void	render_game(t_data *game, int x, int y)
{
	if (game->map.grid[y][x] == '0')
		render_space(game, x, y);
	if (game->map.grid[y][x] == '1')
		render_wall(game, x, y);
	if (game->map.grid[y][x] == 'C')
		render_collectible(game, x, y);
	if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->portal.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map.grid[y][x] == 'P')
		render_astronaut(game, x, y);
}
