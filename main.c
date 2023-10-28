










#include "fractol.h"


int	main(int ac, char **av)
{

	t_fractal	fractal;
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		//it's right bby let's go
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection); mlx_ptr:
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, 1); //TODO
		exit(EXIT_FAILURE);
	}
}