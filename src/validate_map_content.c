/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/15 17:02:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	parse_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->grid[y][x] == 'P')
				map->player_count++;
			else if (map->grid[y][x] == 'C')
				map->collect_count++;
			else if (map->grid[y][x] == 'E')
				map->exit_count++;
			else if (ft_strchr("01CEPX", map->grid[y][x]) == NULL)
			{
				free_map(map);
				handle_error(1, "Map with invalid component!\n");
			}
			x++;
		}
		y++;
	}
}

static void	check_content_count(t_map *map)
{
	if (map->player_count != 1)
	{
		free_map(map);
		handle_error(1, "Map must have one starting position!\n");
	}
	else if (map->collect_count < 1)
	{
		free_map(map);
		handle_error(1, "Map must have at least one collectible!\n");
	}
	if (map->exit_count != 1)
	{
		free_map(map);
		handle_error(1, "Map must have one exit!\n");
	}
}

static void	check_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		if (map->grid[0][i] != '1' || map->grid[map->rows - 1][i] != '1')
		{
			free_map(map);
			handle_error(1, "Map must be surrounded by walls!\n");
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->columns - 1] != '1')
		{
			free_map(map);
			handle_error(1, "Map must be surrounded by walls!\n");
		}
		i++;
	}
}

void	validate_map_content(t_map *map)
{
	map->player_count = 0;
	map->collect_count = 0;
	map->exit_count = 0;
	parse_map(map);
	check_content_count(map);
	check_map_walls(map);
}
