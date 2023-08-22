/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:37:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/10 12:49:33 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_front_is_wall(t_data *game, int x, int y)
{
	if (game->astronaut.direction == 'u')
		y--;
	else if (game->astronaut.direction == 'd')
		y++;
	else if (game->astronaut.direction == 'r')
		x++;
	else if (game->astronaut.direction == 'l')
		x--;
	if (game->map.grid[y][x] == '1')
		return (1);
	else
		return (0);
}

void	move_up(t_data *game, t_player *astronaut)
{
	astronaut->direction = 'u';
	if (check_front_is_wall(game, astronaut->x, astronaut->y) != 1)
	{
		game->map.grid[astronaut->y][astronaut->x] = '0';
		astronaut->y--;
		game->map.grid[astronaut->y][astronaut->x] = 'P';
		astronaut->move_count++;
		ft_printf("Movement count = %d\n", astronaut->move_count);
	}
}

void	move_down(t_data *game, t_player *astronaut)
{
	astronaut->direction = 'd';
	if (check_front_is_wall(game, astronaut->x, astronaut->y) != 1)
	{
		game->map.grid[astronaut->y][astronaut->x] = '0';
		astronaut->y++;
		game->map.grid[astronaut->y][astronaut->x] = 'P';
		astronaut->move_count++;
		ft_printf("Movement count = %d\n", astronaut->move_count);
	}
}

void	move_right(t_data *game, t_player *astronaut)
{
	astronaut->direction = 'r';
	if (check_front_is_wall(game, astronaut->x, astronaut->y) != 1)
	{
		game->map.grid[astronaut->y][astronaut->x] = '0';
		astronaut->x++;
		game->map.grid[astronaut->y][astronaut->x] = 'P';
		astronaut->move_count++;
		ft_printf("Movement count = %d\n", astronaut->move_count);
	}
}

void	move_left(t_data *game, t_player *astronaut)
{
	astronaut->direction = 'l';
	if (check_front_is_wall(game, astronaut->x, astronaut->y) != 1)
	{
		game->map.grid[astronaut->y][astronaut->x] = '0';
		astronaut->x--;
		game->map.grid[astronaut->y][astronaut->x] = 'P';
		astronaut->move_count++;
		ft_printf("Movement count = %d\n", astronaut->move_count);
	}
}
