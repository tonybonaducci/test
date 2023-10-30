#include "fractol.h"

t_complex	sum_tricorn(t_complex z1, t_complex z2)
{
	t_complex	result;
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return result;
}

t_complex	square_tricorn(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = -2 * z.x * z.y;
	return result;
}



void	tricorn_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			rgb;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->iterations)
	{
		z = sum_tricorn(square_tricorn(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractal->hypo_spin)
		{
			rgb = scale(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, rgb);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}