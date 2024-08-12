/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:58:51 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/12 16:13:41 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	argc = 4;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (1);
		if (argv[i][++j] == '.')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	long	integer;
	double	fraction;
	double	power;

	sign = 1;
	integer = 0;
	fraction = 0.0;
	power = 1.0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s && *s != '.')
		if (*s >= '0' && *s <= '9')
			integer = integer * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		fraction = fraction * 10 + (*s++ - '0');
		power *= 10;
	}
	return (sign * (integer + (fraction / power)));
}
