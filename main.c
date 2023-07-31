/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/07/31 10:34:38 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_img
{
	void*	img;
}	t_img;

int	main(void)
{
	void*	mlx_connection;
	t_img	img;
//	void*	mlx_window;

	mlx_connection = mlx_init();
	img = mlx_new_image(mlx_connectio, 1920, 1080);
	mlx_get_data_addr(img.img, );
//	mlx_window = mlx_new_window(mlx_connection, 1920, 1080, "GNL");
//	mlx_loop(mlx_connection);
	return (0);
}
