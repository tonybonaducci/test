/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:59:25 by rmenezes          #+#    #+#             */
/*   Updated: 2023/10/30 16:16:06 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_shuffle(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->id == JULIA)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	my_pixel_put(int x, int y, t_img *img, int rgb)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = rgb;
}

void	pixel_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			rgb;

	i = 0;
	z.x = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	set_shuffle(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypo_spin)
		{
			rgb = scale(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, rgb);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	if (fractal->id == MANDELBROT || fractal->id == JULIA)
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				pixel_calc(x, y, fractal);
		}
	}
	else if (fractal -> id == TRICORN)
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				tricorn_calc(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, 
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

	/*
	else if(fractal -> id == BURNING_SHIP)
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x <WIDTH)
				burning_ship_calc(x, y, fractal);
		}
	}
	*/

/*
void	burning_ship_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			rgb;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, +2, -2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (scale(y, -2, +2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypo_spin)
		{
			rgb = scale(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, rgb);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}
*/