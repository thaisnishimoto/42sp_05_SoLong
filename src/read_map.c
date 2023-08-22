/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/21 17:58:12 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_map_file(int argc, t_map *map)
{
	int		fd;
	char	buffer[1];

	if (argc < 2)
		handle_error(1, 0, "Usage: ./so_long <filename.ber>\n", NULL);
	if (argc > 2)
		handle_error(1, 0, "Please insert one map only!\n", NULL);
	if (ft_strnstr(map->file, ".ber", ft_strlen(map->file)) == NULL)
		handle_error(1, 0, "Map not in .ber extension!\n", NULL);
	fd = open(map->file, O_RDWR);
	if (fd == -1)
		handle_error(1, 1, "Error\n", NULL);
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		handle_error(1, 0, "Map file is empty!\n", NULL);
	}
	close(fd);
}

static void	size_map(t_map *map)
{
	int		fd;
	int		map_shape;
	char	*line;

	map->columns = 0;
	map->rows = 0;
	map_shape = 0;
	fd = open(map->file, O_RDWR);
	line = ft_get_next_line(fd);
	map->columns = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		map->rows++;
		line = ft_get_next_line(fd);
		if (line && ft_strlen(line) - 1 != (size_t)map->columns)
			map_shape = 1;
	}
	if (map_shape == 1)
	{
		close(fd);
		handle_error(1, 0, "Map must be rectangular!\n", NULL);
	}
	close (fd);
}

static void	allocate_map_content(t_map *map)
{
	int	fd;
	int	y;

	y = 0;
	map->grid = malloc((map->rows) * sizeof(char *));
	if (map->grid == NULL)
		handle_error(1, 1, "Error\n", NULL);
	fd = open(map->file, O_RDWR);
	while (y < map->rows)
	{
		map->grid[y] = ft_get_next_line(fd);
		ft_printf("%s", map->grid[y]);
		y++;
	}
	close (fd);
}

void	read_map(int argc, t_map *map)
{
	check_map_file(argc, map);
	size_map(map);
	allocate_map_content(map);
}
