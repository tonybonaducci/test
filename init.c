#include "fractol.h"
# include "minilibx/mlx.h"





void	data_init(t_fractal *fractal)
{
	fractal->hypo_spin = 4;
	fractal->iterations = 42;

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

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
												&fractal->img.bpp, 
												&fractal->img.line_len, 
												&fractal->img.endian);
	data_init(fractal);
}

static void	malloc_error(void)
{
	perror("Malloc go bad :( ");
	exit(EXIT_FAILURE);
}

