#include "fractol.h"
#include <stdio.h>







int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
	

	return 0;
}