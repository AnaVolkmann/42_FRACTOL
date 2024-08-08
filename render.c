/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:07:26 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/08 16:17:00 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/** @brief put a pixel in the image buffer*/
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/** checking if the point escaped, how many times to iterate
 * z^2 + c */
static void	handdle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int i;
	int	color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, HOT_PINK);
}

void	fractal_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handdle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
							fractal->img.img_ptr, 0, 0);
}