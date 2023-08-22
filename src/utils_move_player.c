/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:37:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/22 16:35:14 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_next_step(t_data *game, t_player *astronaut, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
		game->map.collect_count--;
	if (game->map.grid[y][x] == 'E')
	{
		if (game->map.collect_count == 0)
		{
			game->map.grid[astronaut->y][astronaut->x] = '0';
			game->map.grid[y][x] = 'P';
			astronaut->move_count++;
			ft_printf("Movement count = %d\n", astronaut->move_count);
			ft_printf("YOU WIN!!!\n");
			close_window(game);
			free_map(&game->map);
			free_sprites(game);
			end_mlx_connection(game);
			exit (0);
		}
		ft_printf("Oxygens left to collect: %d\n", game->map.collect_count);
		return ;
	}
	game->map.grid[astronaut->y][astronaut->x] = '0';
	game->map.grid[y][x] = 'P';
	astronaut->move_count++;
	ft_printf("Movement count = %d\n", astronaut->move_count);
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
	}
}
