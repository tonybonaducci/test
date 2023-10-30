/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:35 by rmenezes          #+#    #+#             */
/*   Updated: 2023/10/30 15:59:59 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

void	data_init(t_fractal *fractal)
{
	fractal->hypo_spin = 4;
	fractal->iterations = 10;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
}

static void	malloc_error(void)
{
	perror("Malloc go bad :( ");
	exit(EXIT_FAILURE);
}

void	img_destroy(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	malloc_error();
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, 
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
		img_destroy(fractal);
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, 
			&fractal->img.line_len, 
			&fractal->img.endian);
	data_init(fractal);
	event_init(fractal);
}
