/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:39:04 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 16:46:24 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		end_game(game);
	return (0);
}

int	render_hook(t_data *game)
{
	int	x;
	int	y;

	if (game->win.mlx_win == NULL)
		return (1);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			render_game(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
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
	if (game->map.grid[y][x] == 'B')
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->block_exit.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map.grid[y][x] == 'H')
		render_black_hole(game, x, y);
	display_on_screen(game);
}
