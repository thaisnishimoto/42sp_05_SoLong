/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:37:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 10:20:34 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_next_step(t_data *game, t_player *astronaut, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
		game->map.collect_count--;
	if (game->map.grid[y][x] == 'E')
	{
		game->map.grid[astronaut->y][astronaut->x] = '0';
		game->map.grid[y][x] = 'B';
		if (game->map.collect_count == 0)
		{
			astronaut->move_count++;
			ft_printf("YOU WIN!!!\n");
			close_window(game);
			free_map(&game->map);
			free_sprites_background(game);
			free_sprites_items(game);
			free_sprites_player(game);
			end_mlx_connection(game);
			exit (0);
		}
		ft_printf("Stars left to collect: %d\n", game->map.collect_count);
		return ;
	}
	if (game->map.grid[astronaut->y][astronaut->x] == 'B')
		game->map.grid[astronaut->y][astronaut->x] = 'E';
	else
		game->map.grid[astronaut->y][astronaut->x] = '0';
	game->map.grid[y][x] = 'P';
}

void	move_up(t_data *game, t_player *astronaut)
{
	int	x;
	int	y;

	astronaut->direction = 'u';
	x = astronaut->x;
	y = astronaut->y - 1;
	if (game->map.grid[y][x] != '1')
	{
		handle_next_step(game, astronaut, x, y);
		astronaut->y--;
		astronaut->move_count++;
	}
}

void	move_down(t_data *game, t_player *astronaut)
{
	int	x;
	int	y;

	astronaut->direction = 'd';
	x = astronaut->x;
	y = astronaut->y + 1;
	if (game->map.grid[y][x] != '1')
	{
		handle_next_step(game, astronaut, x, y);
		astronaut->y++;
		astronaut->move_count++;
	}
}

void	move_right(t_data *game, t_player *astronaut)
{
	int	x;
	int	y;

	astronaut->direction = 'r';
	x = astronaut->x + 1;
	y = astronaut->y;
	if (game->map.grid[y][x] != '1')
	{
		handle_next_step(game, astronaut, x, y);
		astronaut->x++;
		astronaut->move_count++;
	}
}

void	move_left(t_data *game, t_player *astronaut)
{
	int	x;
	int	y;

	astronaut->direction = 'l';
	x = astronaut->x - 1;
	y = astronaut->y;
	if (game->map.grid[y][x] != '1')
	{
		handle_next_step(game, astronaut, x, y);
		astronaut->x--;
		astronaut->move_count++;
	}
}
