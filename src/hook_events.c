/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:39:04 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 16:53:35 by tmina-ni         ###   ########.fr       */
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
		close_window(game);
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
