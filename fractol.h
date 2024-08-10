/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:33:45 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/10 20:40:34 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \
\n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH	800
# define HEIGHT	800

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300
# define CYAN           0x00FFFF  // RGB(0, 255, 255)
# define YELLOW         0xFFFF00  // RGB(255, 255, 0)
# define TURQUOISE      0x40E0D0  // RGB(64, 224, 208)

/** x = real
	y = imaginary*/
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;//pointer to img struct
	char	*pixels_ptr;//pointer to the actual pixel
	int		bits_per_pixel;
	int		endian;
	int		line_len;

}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;//mlx_connection()
	void	*mlx_window;//mlx_new_window()
	t_img	img;//image
	double	escape_value;//hypotenuse
	int		iterations_definition;//image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		dynamic_update;
}				t_fractal;
/*----------------------STRING_UTILS-----------------------*/

int			ft_strncmp(char *s1, char *s2, int n);
double		ft_atodbl(char *s);
void		putstr_fd(char *s, int fd);

/*---------------------------INIT-------------------------*/

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

/*------------------------MATH_UTILS-----------------------*/

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);

/*--------------------------EVENTS--------------------------*/

int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_motion(int x, int y, t_fractal *fractal);

#endif