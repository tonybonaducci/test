#include "fractol.h"

void error_exit(void)
{
	putstr_fd(ERROR_MESSAGE, 1);
	exit(EXIT_FAILURE);
}