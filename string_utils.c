/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:58:51 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/06 14:06:31 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1)
		{
			++s1;
			++s2;
			--n;
		}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

/** @brief - ALPHA TO DOUBLE
similar to atoi, but dealing with floats
takes the command line args and converts to long double*/
double	ft_atodbl(char *s)
{
	int		sign;
	long 	integer;
	double	divider;
	double	fraction;

	sign = 1;
	integer = 0;
	divider = 0;
	fraction = 0;
	if ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s && *s != '.')
		integer = integer * 10 + (*s++ - 48);
	if ( *s == '.')
		++*s;
	while (*s)
	{
		divider /= 10;
		fraction = fraction + (*s++ - 48) * divider;
	}
	return ((integer + fraction) * sign);
}
