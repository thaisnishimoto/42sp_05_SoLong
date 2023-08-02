/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_aurelian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:28:43 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/02 13:15:21 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define BLUE_PIXEL 0xFF
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_img	img;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int render_backgroud(t_img *img, int color)
{
    int	i;
    int j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
    return (0);
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
    render_backgroud(&data->img, WHITE_PIXEL);
    render_rect(&data->img, (t_rect){0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GREEN_PIXEL});
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return (0);
}

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }

    data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

    data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

    /* Setup hooks */ 
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}
