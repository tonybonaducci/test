/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:57:29 by rmenezes          #+#    #+#             */
/*   Updated: 2023/10/30 16:17:09 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "invalid input, try mandelbrot, julia, tricorn \n"
# define WIDTH 800
# define HEIGHT 800
/*		SETS		*/

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

/*
		******* BORING COLORS *****
*/
# define BLACK       0x000000  // Black
# define WHITE       0xFFFFFF  // White
# define RED         0xFF0000  // Red
# define GREEN       0x00FF00  // Green
# define BLUE        0x0000FF  // Blue
/*    
		****** FUN COLORS ******
*/

# define PSYCHEDELIC_PURPLE 0xA020F0  // A bright purple color
# define PSYCHEDELIC_YELLOW 0xFFFF00  // A vibrant yellow color
# define PSYCHEDELIC_PINK 0xFF1493    // A hot pink color
# define PSYCHEDELIC_CYAN 0x00FFFF    // A bright cyan color
# define PSYCHEDELIC_ORANGE 0xFFA500  // A fiery orange color
# define PSYCHEDELIC_GREEN 0x00FF00
# define WACKY_PINK 0xFF6EC7
# define WACKY_GREEN 0x56FF00
# define WACKY_ORANGE 0xFFA200
# define SCARY_PURPLE 0x8B00FF
# define GENRE_DEFINING_COLOR 0xF08080

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	hypo_spin;
	t_img	img;
	int		iterations;
	int		id;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/*
*********	STRING_UTIlS.C      *********
*/
double		atodbl(char *s);
void		putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strchr(const char *s, int c);
/*
*********   INIT.C FUNCTIONS    *********
*/
void		fractal_init(t_fractal *fractal);
/*
********	Render Functions 	********
*/
void		fractal_render(t_fractal *fractal);
void		tricorn_calc(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int rgb);
/*
********	Math functions      *********
*/
double		scale(double unscaled_num, double new_min, 
				double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
/*
*******		events functions	*********
*/
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
void		error_exit(void);

#endif
