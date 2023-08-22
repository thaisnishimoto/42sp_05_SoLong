/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:10:01 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/21 22:44:40 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	allocate_flag_grid(t_data *game, t_map *seen_flag)
{
	int	y;

	y = 0;
	seen_flag->columns = game->map.columns;
	seen_flag->rows = game->map.rows;
	seen_flag->grid = ft_calloc(seen_flag->rows, sizeof(char *));
	if (seen_flag->grid == NULL)
		handle_error(2, 1, "Error\n", game);
	while (y < game->map.rows)
	{
		seen_flag->grid[y] = ft_calloc(seen_flag->columns, sizeof(char));
		if (seen_flag->grid[y] == NULL)
		{
			y--;
			while (y > 0)
				free(seen_flag->grid[y--]);
			free(seen_flag->grid);
			handle_error(2, 1, "Error\n", game);
		}
		y++;
	}
}

static void	find_start_position(t_data *game, t_map *seen_flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->astronaut.x = x;
				game->astronaut.y = y;
				seen_flag->grid[y][x] = 1;
			}
			x++;
		}
		y++;
	}
}

static char	tile_is_valid(t_data *game, int x, int y, t_map *seen_flag)
{
	char	valid_tile;

	valid_tile = 0;
	if (seen_flag->grid[y][x] == 0 && game->map.grid[y][x] != '1')
		valid_tile = 1;
	seen_flag->grid[y][x] = 1;
	return (valid_tile);
}

/*Check neighbor tiles in order: up(0.-1), right(1.0), down(0. 1), left(-1.0)*/
/*Look every tile using Depth First Search Algorithm*/
void	check_neighbors(t_data *game, int curr_x, int curr_y, t_map *seen_flag)
{
	int		i;
	int		x;
	int		y;
	t_dir	dir;

	i = 0;
	dir = (t_dir){.x = {0, 1, 0, -1}, .y = {-1, 0, 1, 0}};
	while (i < 4)
	{
		x = curr_x + dir.x[i];
		y = curr_y + dir.y[i];
		if (x >= 0 && x < game->map.columns && y >= 0 && y < game->map.rows)
		{
			if (game->map.grid[y][x] == 'E')
				seen_flag->valid_path = 1;
			if (game->map.grid[y][x] == 'C')
				seen_flag->collect_count++;
			if (tile_is_valid(game, x, y, seen_flag) == 1)
				check_neighbors(game, x, y, seen_flag);
		}
		i++;
	}
}

void	check_valid_path(t_data *game)
{
	t_map	seen_flag;		

	seen_flag.valid_path = 0;
	seen_flag.collect_count = 0;
	allocate_flag_grid(game, &seen_flag);
	find_start_position(game, &seen_flag);
	check_neighbors(game, game->astronaut.x, game->astronaut.y, &seen_flag);
	if (seen_flag.valid_path == 0)
	{
		free_map(&seen_flag);
		handle_error(2, 0, "Invalid path to exit!\n", game);
	}
	if (seen_flag.collect_count < game->map.collect_count)
	{
		free_map(&seen_flag);
		handle_error(2, 0, "Invalid path to collectibles!\n", game);
	}
	free_map(&seen_flag);
}
