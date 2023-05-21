/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:25:34 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/21 16:38:47 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	fractal_bonus(int i, int argc, char **argv)
{
	t_fract	data;

	data.i = i;
	data.ac = argc;
	data.av = argv;
	if (i == 1)
		mandelbrot_bonus(data);
	else if (i == 2)
		julia_bonus(data);
	else if (i == 3)
		burning_ship_bonus(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "M") == 0 || \
			ft_strcmp(argv[1], "m") == 0)
			return (fractal_bonus(1, argc, argv));
		else if (ft_strcmp(argv[1], "J") == 0 || \
			ft_strcmp(argv[1], "j") == 0)
			return (fractal_bonus(2, argc, argv));
		else if (ft_strcmp(argv[1], "B") == 0 || \
			ft_strcmp(argv[1], "b") == 0)
			return (fractal_bonus(3, argc, argv));
		else
			ft_menubonus();
	}
	else
		ft_menubonus();
	return (0);
}
