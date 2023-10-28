#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx/mlx.h"
# include <X11/X.h>

#define ERROR_MESSAGE "wrong name dummy"
#define WIDTH 800
#define HEIGHT 800

/*
		******* BORING COLORS *****
*/
#define BLACK       0x000000  // Black
#define WHITE       0xFFFFFF  // White
#define RED         0xFF0000  // Red
#define GREEN       0x00FF00  // Green
#define BLUE        0x0000FF  // Blue
/*    
		****** FUN COLORS ******
*/
#define WACKY_PINK 0xFF6EC7    // A vibrant and wacky pink
#define WACKY_GREEN 0x56FF00   // A wild and eye-popping green
#define WACKY_ORANGE 0xFFA200  // A bold and crazy orange
#define SCARY_PURPLE 0x8B00FF  // A mysterious and haunting purple

// A combination of wacky and scary for genre-defining effects
#define GENRE_DEFINING_COLOR 0xF08080  // A unique and genre-defining color


typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
} t_img;


typedef	struct s_fractal
{

	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	hypo_spin;
	t_img	img;
	int		iterations;
	double	shift_x;
	double	shift_y;

} t_fractal;


typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;


/*
*********	STRING_UTIlS.C      *********
*/

double	atodbl(char *s);
void	putstr_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, int n);


/*
*********   INIT.C FUNCTIONS    *********
*/
void	fractal_init(t_fractal *fractal);
static void	malloc_error(void);

/*
********	Render Functions 	********
*/
void	fractal_render(t_fractal *fractal);


/*
********	Math functions      *********
*/
double	scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);


#endif

