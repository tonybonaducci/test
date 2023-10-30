/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:54 by rmenezes          #+#    #+#             */
/*   Updated: 2023/10/30 16:17:22 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_check(t_fractal *fractal, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 10))
		fractal->id = MANDELBROT;
	else if ((!ft_strncmp(av[1], "julia", 5)))
		fractal->id = JULIA;
	else if ((!ft_strncmp(av[1], "tricorn", 7)))
		fractal->id = TRICORN;
	else
		error_exit();
}

static void	julia_handler(t_fractal *fractal, int ac, char **av)
{
	if (ac == 2)
	{
		fractal->julia_x = -0.766667;
		fractal->julia_y = -0.090000;
		return ;
	}
	if (ac == 3)
		error_exit();
	if (!ft_strchr(av[2], '.'))
		error_exit();
	if (!ft_strchr(av[3], '.'))
		error_exit();
	fractal->julia_x = atodbl(av[2]);
	fractal->julia_y = atodbl(av[3]);
	if (fractal->julia_x > 2.0 || fractal->julia_x < -2.0)
		error_exit();
	if (fractal->julia_y > 2.0 || fractal->julia_y < -2.0)
		error_exit();
}

static void	arg_handler(t_fractal *fractal, int ac, char **av)
{
	set_check(fractal, av);
	if (fractal->id == JULIA)
		julia_handler(fractal, ac, av);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac >= 2)
	{
		arg_handler(&fractal, ac, av);
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
}
