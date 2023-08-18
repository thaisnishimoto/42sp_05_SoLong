/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/17 20:16:45 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_map_file(int argc, t_map *map)
{
	int		fd;
	char	buffer[1];

	if (argc < 2)
		handle_error(1, "Usage: ./so_long <filename.ber>\n");
	if (argc > 2)
		handle_error(1, "Please insert one map only!\n");
	if (ft_strnstr(map->file, ".ber", ft_strlen(map->file)) == NULL)
		handle_error(1, "Map not in .ber extension!\n");
	fd = open(map->file, O_RDWR);
	if (fd == -1)
		handle_error(2, "Error\n");
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		handle_error(1, "Map file is empty!\n");
	}
	close(fd);
}

static void	size_map(t_map *map)
{
	size_t	line_len;
	int		fd;
	char	*line;

	map->columns = 0;
	map->rows = 0;
	fd = open(map->file, O_RDWR);
	line = ft_get_next_line(fd);
	line_len = ft_strlen(line);
	while (line)
	{
		free(line);
		map->rows++;
		line = ft_get_next_line(fd);
		if (line && ft_strlen(line) != line_len)
		{
			free(line);
			close(fd);
			handle_error(1, "Map must be rectangular!\n");
		}
	}
	map->columns = line_len - 1;
	close (fd);
}

static void	allocate_map_content(t_map *map)
{
	int	fd;
	int	y;

	y = 0;
	map->grid = malloc((map->rows) * sizeof(char *));
	if (map->grid == NULL)
		handle_error(2, "Error\n");
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
