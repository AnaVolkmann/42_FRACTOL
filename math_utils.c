/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:39:18 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/08 14:09:10 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/** @brief linear interpolation
 * [0..799] -> [-2..+2]
*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

/** @brief vector addiction
 * (x, y) + (x, y)
 * 	\z1       \z2
*/
t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

/** @brief square a number
 real = (x^2 - y^2)
 i =  2*x*y
*/
t_complex   square_complex(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}