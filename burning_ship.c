#include "fractol.h"



void burning_ship_calc(int x, int y, t_fractal *fractal)
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
		z = sum_complex(square_complex(z), c);
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		if((z.x * z.x) + (z.y * z.y) > fractal->hypo_spin)
		{
			rgb = scale(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, rgb);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}