/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 15:24:44 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_map_file(int argc, t_data *game)
{
	int		fd;
	char	buffer[1];

	if (argc < 2)
		handle_error(0, "Usage: ./so_long <filename.ber>\n", game);
	if (argc > 2)
		handle_error(0, "Please insert one map only!\n", game);
	if (ft_strnstr(game->map.file, ".ber", ft_strlen(game->map.file)) == NULL)
		handle_error(0, "Map not in .ber extension!\n", game);
	fd = open(game->map.file, O_RDWR);
	if (fd == -1)
		handle_error(1, "Error\n", game);
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		handle_error(0, "Map file is empty!\n", game);
	}
	close(fd);
}

static void	size_map(t_data *game)
{
	int		fd;
	int		map_shape;
	char	*line;

	game->map.columns = 0;
	game->map.rows = 0;
	map_shape = 0;
	fd = open(game->map.file, O_RDWR);
	line = ft_get_next_line(fd);
	game->map.columns = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		game->map.rows++;
		line = ft_get_next_line(fd);
		if (line && ft_strlen(line) - 1 != (size_t)game->map.columns)
			map_shape = 1;
	}
	if (map_shape == 1)
	{
		close(fd);
		handle_error(0, "Map must be rectangular!\n", game);
	}
	close (fd);
}

static void	allocate_map_content(t_data *game)
{
	int	fd;
	int	y;

	y = 0;
	game->map.grid = malloc((game->map.rows) * sizeof(char *));
	if (game->map.grid == NULL)
		handle_error(1, "Error\n", game);
	fd = open(game->map.file, O_RDWR);
	while (y < game->map.rows)
	{
		game->map.grid[y] = ft_get_next_line(fd);
		y++;
	}
	close (fd);
}

void	read_map(int argc, t_data *game)
{
	game->config_stage = 1;
	check_map_file(argc, game);
	size_map(game);
	allocate_map_content(game);
}
