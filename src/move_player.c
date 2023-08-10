/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:37:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/09 19:17:42 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data *game, t_player *astronaut)
{
	game->map.grid[astronaut->y][astronaut->x] = '0';
	astronaut->y--;
	game->map.grid[astronaut->y][astronaut->x] = 'P';
	astronaut->direction = 'u';
	astronaut->move_count++;
	ft_printf("Movement count = %d\n", astronaut->move_count);
}

void	move_down(t_data *game, t_player *astronaut)
{
	game->map.grid[astronaut->y][astronaut->x] = '0';
	astronaut->y++;
	game->map.grid[astronaut->y][astronaut->x] = 'P';
	astronaut->direction = 'd';
	astronaut->move_count++;
	ft_printf("Movement count = %d\n", astronaut->move_count);
}

void	move_right(t_data *game, t_player *astronaut)
{
	game->map.grid[astronaut->y][astronaut->x] = '0';
	astronaut->x++;
	game->map.grid[astronaut->y][astronaut->x] = 'P';
	astronaut->direction = 'r';
	astronaut->move_count++;
	ft_printf("Movement count = %d\n", astronaut->move_count);
}

void	move_left(t_data *game, t_player *astronaut)
{
	game->map.grid[astronaut->y][astronaut->x] = '0';
	astronaut->x--;
	game->map.grid[astronaut->y][astronaut->x] = 'P';
	astronaut->direction = 'l';
	astronaut->move_count++;
	ft_printf("Movement count = %d\n", astronaut->move_count);
}
