/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:37:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/18 18:23:48 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    handle_error(int stage, char *error_msg)
{
	if (stage == 1)
	{
		ft_printf("Error\n%s", error_msg);
		exit (1);
	}
	if (stage == 2)
	{
		ft_printf("%s", error_msg);
		perror("");
		exit (1);
	}
}

//void	free_map(t_map *map)
//{
//	int	y;
//
//	y = 0;
//	while (y < map->rows)
//	{
//		free(map->grid[y]);
//		y++;
//	}
//	free(map->grid);
//}
//
//void	end_game(t_data* game)
//{
//	ft_printf("End game funcion");
//	free_map(&game->map);
//	mlx_destroy_image(game->mlx_connection, game->space1.ptr);
//	mlx_destroy_image(game->mlx_connection, game->space2.ptr);
//	mlx_destroy_image(game->mlx_connection, game->space3.ptr);
//	mlx_destroy_image(game->mlx_connection, game->space4.ptr);
//	mlx_destroy_image(game->mlx_connection, game->asteroid.ptr);
//	mlx_destroy_image(game->mlx_connection, game->oxygen.ptr);
//	mlx_destroy_image(game->mlx_connection, game->portal.ptr);
//	mlx_destroy_image(game->mlx_connection, game->astronaut.u_ptr);
//	mlx_destroy_image(game->mlx_connection, game->astronaut.d_ptr);
//	mlx_destroy_image(game->mlx_connection, game->astronaut.r_ptr);
//	mlx_destroy_image(game->mlx_connection, game->astronaut.l_ptr);
//	mlx_destroy_display(game->mlx_connection);
//	free(game->mlx_connection);
//}
