/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:08:35 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/25 12:38:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_black_hole(t_data *game, int x, int y)
{
	static int	i;

	if (i >= 0 && i <= REPEAT_FRAME)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->hole.ptr1, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME && i <= REPEAT_FRAME * 2)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->hole.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 2 && i <= REPEAT_FRAME * 3)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->hole.ptr3, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 3 && i <= REPEAT_FRAME * 4)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->hole.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	if (i > REPEAT_FRAME * 4)
		i = 0;
	i++;
}

void	display_on_screen(t_data *game)
{
	char	*move_count;
	char	*collect_count;
	int		x;

	if (game->astronaut.move_count < 10)
		x = 29;
	else
		x = 26;
	move_count = ft_itoa(game->astronaut.move_count);
	collect_count = ft_itoa(game->map.collect_count);
	mlx_string_put(game->mlx_connection, game->win.mlx_win,
		x, 44, 0xFFFFFF, move_count);
	mlx_string_put(game->mlx_connection, game->win.mlx_win,
		29, 113, 0xFFFFFF, collect_count);
	free(move_count);
	free(collect_count);
}

void	render_victory_ending(t_data *game, int x, int y)
{
	int	i;

	i = 0;
	render_hook(game);
	mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
		game->you_win.ptr, game->map.columns * .42 * TILE_SIZE, 0);
	while (i++ <= REPEAT_FRAME * 300)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->win_portal.ptr1, x * TILE_SIZE, y * TILE_SIZE);
	while (i > REPEAT_FRAME * 300 && i++ <= REPEAT_FRAME * 600)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->win_portal.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	while (i > REPEAT_FRAME * 600 && i++ <= REPEAT_FRAME * 900)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->win_portal.ptr3, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_lose_ending(t_data *game, int x, int y)
{
	int	i;

	i = 0;
	render_hook(game);
	mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
		game->game_over.ptr, game->map.columns * .42 * TILE_SIZE, 0);
	while (i++ <= REPEAT_FRAME * 300)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->lose_hole.ptr1, x * TILE_SIZE, y * TILE_SIZE);
	while (i > REPEAT_FRAME * 300 && i++ <= REPEAT_FRAME * 600)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->lose_hole.ptr2, x * TILE_SIZE, y * TILE_SIZE);
	while (i > REPEAT_FRAME * 600 && i++ <= REPEAT_FRAME * 900)
		mlx_put_image_to_window(game->mlx_connection, game->win.mlx_win,
			game->lose_hole.ptr3, x * TILE_SIZE, y * TILE_SIZE);
}
