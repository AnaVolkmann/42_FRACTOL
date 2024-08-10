/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:16:06 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/10 20:07:40 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * ESC/press the x
 * int (*f)(void *param)
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/** keypress prototype 
 * int (*f)(int keycode, void *param)*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 61 || keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	else if (keysym == XK_space)
		fractal->dynamic_update = !fractal->dynamic_update;
	fractal_render(fractal);
	return (0);
}

/*int (*f)(int button, int x, int y, void *param)
mous variables store the loc of the mouse & the calc.
convert pixel coordinates into the corresponding
 coordinates on the complex plane.*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = (x / (double)WIDTH) * 4.0 - 2.0;
	mouse_im = (y / (double)HEIGHT) * 4.0 - 2.0;
	if (button == Button4)
		zoom_factor = 0.95;
	else if (button == Button5)
		zoom_factor = 1.05;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal->shift_x = (fractal->shift_x - mouse_re) * zoom_factor + mouse_re;
	fractal->shift_y = (fractal->shift_y - mouse_im) * zoom_factor + mouse_im;
	fractal_render(fractal);
	return (0);
}

/** @brief track the mouse movement to chache the set \ 
 * int (*f)(int x, int y, void *param)*/
int	julia_motion(int x, int y, t_fractal *fractal)
{
	if (fractal->dynamic_update && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = fractal->shift_x + ((x - (WIDTH / 2.0))
				/ (WIDTH / 4.0)) / fractal->zoom;
		fractal->julia_y = fractal->shift_y + ((y - (HEIGHT / 2.0))
				/ (HEIGHT / 4.0)) / fractal->zoom;
		fractal_render(fractal);
	}
	return (0);
}
