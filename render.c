#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int rgb)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp/8));
	*(unsigned int *)(img->pixel_ptr + offset) = rgb;

}

void pixel_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			rgb;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = scale(x, -2, +2, 0, WIDTH);
	c.y = scale(y, +2, -2, 0, HEIGHT);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractal->hypo_spin)
		{
			rgb = scale(i, BLACK, WHITE, 0, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, rgb);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WACKY_PINK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y= -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_calc(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}