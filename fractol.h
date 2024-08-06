/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:33:45 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/06 14:48:10 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH	800
#define HEIGHT	800

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;     //pointer to img struct
	char	*pixels_ptr;  //pointer to the actual pixel
	int		bits_per_pixel;
	int		endian;
	int		line_len;

}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection; 		 //mlx_connection()
	void	*mlx_window;     		 //mlx_new_window()
	t_img	img;             		 //image
	double	escape_value;  		 	 //hypotenuse
	int		iterations_definition; 	 //value adjusted to image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	
}				t_fractal;
/*------------------------STRING_UTILS-----------------------*/

int	ft_strncmp(char *s1, char *s2, int n);
double	ft_atodbl(char *s);
void	putstr_fd(char *s, int fd);

/*------------------------INIT-----------------------*/


void	fractol_init(t_fractal *fractal);

#endif