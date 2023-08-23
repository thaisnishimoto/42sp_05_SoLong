/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 15:42:06 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	parse_map(t_data *game)
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
				game->map.player_count++;
			else if (game->map.grid[y][x] == 'C')
				game->map.collect_count++;
			else if (game->map.grid[y][x] == 'E')
				game->map.exit_count++;
			else if (ft_strchr("01CEPX", game->map.grid[y][x]) == NULL)
				handle_error(0, "Map with invalid component!\n", game);
			x++;
		}
		y++;
	}
}

static void	check_content_count(t_data *game)
{
	if (game->map.player_count != 1)
		handle_error(0, "Map must have one starting position!\n", game);
	if (game->map.collect_count < 1)
		handle_error(0, "Map must have at least one collectible!\n", game);
	if (game->map.exit_count != 1)
		handle_error(0, "Map must have one exit!\n", game);
}

static void	check_map_walls(t_data *game)
{
	int	i;
	int	rows;
	int	cols;

	i = 0;
	rows = game->map.rows;
	cols = game->map.columns;
	while (i < cols)
	{
		if (game->map.grid[0][i] != '1' || game->map.grid[rows - 1][i] != '1')
			handle_error(0, "Map must be surrounded by walls!\n", game);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (game->map.grid[i][0] != '1' || game->map.grid[i][cols - 1] != '1')
			handle_error(0, "Map must be surrounded by walls!\n", game);
		i++;
	}
}

void	validate_map_content(t_data *game)
{
	game->config_stage = 2;
	game->map.player_count = 0;
	game->map.collect_count = 0;
	game->map.exit_count = 0;
	parse_map(game);
	check_content_count(game);
	check_map_walls(game);
}
