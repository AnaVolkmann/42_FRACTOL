/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:16:06 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/12 18:58:22 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_fractal *fractal)
{
	if (fractal->majenta == 1)
	{
		if (fractal->to_fractol != NULL)
			change_color(fractal->to_fractol);
	}
	if (fractal->color_1 == WHITE && fractal->color_2 == BLACK)
	{
		fractal->color_1 = GREEN;
		fractal->color_2 = RED;
	}
	else if (fractal->color_1 == GREEN && fractal->color_2 == RED)
	{
		fractal->color_1 = PURPLE;
		fractal->color_2 = YELLOW;
	}
	else if (fractal->color_1 == PURPLE && fractal->color_2 == YELLOW)
	{
		fractal->color_1 = WHITE;
		fractal->color_2 = BLACK;
	}
}

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
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		change_color(fractal);
	fractal_render(fractal);
	return (0);
}

/*int (*f)(int button, int x, int y, void *param)
mouse variables store the loc of the mouse & the calc.
convert pixel coordinates into the corresponding
 coordinates on the complex plane.*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	mouse_im = map(y, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
	if (button == Button4)
		fractal->zoom /= 1.1;
	else if (button == Button5)
		fractal->zoom *= 1.1;
	fractal->shift_x = mouse_re - (mouse_re - fractal->shift_x) * fractal->zoom;
	fractal->shift_y = mouse_im - (mouse_im - fractal->shift_y) * fractal->zoom;
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
