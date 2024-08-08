/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:16:06 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/08 19:43:17 by ana-lda-         ###   ########.fr       */
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
int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
   if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)	
		fractal->iterations_definition -= 10;
    fractal_render(fractal);
    return (0);
}

/*int (*f)(int button, int x, int y, void *param)*/
int	mouse_handler(int button, t_fractal *fractal)
{
	if (button == Button5)
    {
		fractal->zoom *= 0.95;
    }
	else if (button == Button4)
	{
    	fractal->zoom *= 1.05;
    }
    fractal_render(fractal);
	return 0;
}