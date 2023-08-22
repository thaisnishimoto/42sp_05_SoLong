/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:39:04 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 00:21:28 by tmina-ni         ###   ########.fr       */
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
