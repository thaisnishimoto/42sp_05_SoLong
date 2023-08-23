/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:13:08 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/23 16:08:08 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_sprites_background(t_data *game)
{
	game->space.ptr1 = mlx_xpm_file_to_image(game->mlx_connection, SPACE1,
			&game->space.width, &game->space.height);
	game->space.ptr2 = mlx_xpm_file_to_image(game->mlx_connection, SPACE2,
			&game->space.width, &game->space.height);
	game->space.ptr3 = mlx_xpm_file_to_image(game->mlx_connection, SPACE3,
			&game->space.width, &game->space.height);
	game->space.ptr4 = mlx_xpm_file_to_image(game->mlx_connection, SPACE4,
			&game->space.width, &game->space.height);
	game->asteroid.ptr = mlx_xpm_file_to_image(game->mlx_connection, ASTEROID,
			&game->asteroid.width, &game->asteroid.height);
	game->move_display.ptr = mlx_xpm_file_to_image(game->mlx_connection, MOVES,
			&game->move_display.width, &game->move_display.height);
	game->star_display.ptr = mlx_xpm_file_to_image(game->mlx_connection, COLLEC,
			&game->star_display.width, &game->star_display.height);
}

static void	init_sprites_items(t_data *game)
{
	game->star.ptr1 = mlx_xpm_file_to_image(game->mlx_connection, STAR1,
			&game->star.width, &game->star.height);
	game->star.ptr2 = mlx_xpm_file_to_image(game->mlx_connection, STAR2,
			&game->star.width, &game->star.height);
	game->star.ptr3 = mlx_xpm_file_to_image(game->mlx_connection, STAR3,
			&game->star.width, &game->star.height);
	game->star.ptr4 = mlx_xpm_file_to_image(game->mlx_connection, STAR4,
			&game->star.width, &game->star.height);
	game->portal.ptr = mlx_xpm_file_to_image(game->mlx_connection, PORTAL,
			&game->portal.width, &game->portal.height);
	game->block_exit.ptr = mlx_xpm_file_to_image(game->mlx_connection, BLOCK_E,
			&game->block_exit.width, &game->block_exit.height);
}

static void	init_sprites_player(t_data *game)
{
	game->astronaut.u_ptr = mlx_xpm_file_to_image(game->mlx_connection, ASTRO_U,
			&game->astronaut.width, &game->astronaut.height);
	game->astronaut.d_ptr = mlx_xpm_file_to_image(game->mlx_connection, ASTRO_D,
			&game->astronaut.width, &game->astronaut.height);
	game->astronaut.r_ptr = mlx_xpm_file_to_image(game->mlx_connection, ASTRO_R,
			&game->astronaut.width, &game->astronaut.height);
	game->astronaut.l_ptr = mlx_xpm_file_to_image(game->mlx_connection, ASTRO_L,
			&game->astronaut.width, &game->astronaut.height);
	game->astronaut.direction = 'd';
	game->astronaut.move_count = 0;
}

static void	init_window(t_data *game)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx_connection, &screen_width, &screen_height);
	game->win.width = game->map.columns * TILE_SIZE;
	game->win.height = game->map.rows * TILE_SIZE;
	if (game->win.width > screen_width || game->win.height > screen_height)
		handle_error(0, "Map is too big for this screen!\n", game);
	game->win.mlx_win = mlx_new_window(game->mlx_connection,
			game->win.width, game->win.height, "SO LONG");
	if (game->win.mlx_win == NULL)
		handle_error(0, "mlx_new_window failed!\n", game);
}

void	initiate_game(t_data *game)
{
	game->mlx_connection = mlx_init();
	if (game->mlx_connection == NULL)
		handle_error(0, "mlx_init failed!\n", game);
	game->config_stage = 3;
	init_sprites_background(game);
	init_sprites_items(game);
	init_sprites_player(game);
	if (game->space.ptr1 == NULL || game->space.ptr2 == NULL
		|| game->space.ptr3 == NULL || game->space.ptr4 == NULL
		|| game->asteroid.ptr == NULL || game->move_display.ptr == NULL
		|| game->star_display.ptr == NULL || game->star.ptr1 == NULL
		|| game->star.ptr2 == NULL || game->star.ptr3 == NULL
		|| game->star.ptr4 == NULL || game->portal.ptr == NULL
		|| game->block_exit.ptr == NULL || game->astronaut.u_ptr == NULL
		|| game->astronaut.d_ptr == NULL || game->astronaut.r_ptr == NULL
		|| game->astronaut.l_ptr == NULL)
		handle_error(0, "XPM image loading failed!\n", game);
	init_window(game);
	game->config_stage = 4;
}
