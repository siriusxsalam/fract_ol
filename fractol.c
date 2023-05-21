/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:29:18 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/21 16:37:09 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

int	fractal(int i, int argc, char **argv)
{
	t_fract	data;

	data.i = i;
	data.ac = argc;
	data.av = argv;
	if (i == 1)
		mandelbrot(data);
	else if (i == 2)
		julia(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "M") == 0 || \
			ft_strcmp(argv[1], "m") == 0)
			return (fractal(1, argc, argv));
		else if (ft_strcmp(argv[1], "J") == 0 || \
			ft_strcmp(argv[1], "j") == 0)
			return (fractal(2, argc, argv));
		else
			ft_menu();
	}
	else
		ft_menu();
	return (0);
}
