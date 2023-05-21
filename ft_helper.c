/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:04:17 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 03:05:50 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu(void)
{
	ft_printf("##########################################\n");
	ft_printf("#\033[0;31m                 ERROR                  \033[0m#\n");
	ft_printf("##########################################\n");
	ft_printf("# Please enter one of the letters bellow #\n");
	ft_printf("#\033[0;32m     For Mandelbrot  	==>   M or m     \033[0m#\n");
	ft_printf("#\033[0;33m     For Julia		==>   J or j     \033[0m#\n");
	ft_printf("##########################################\n");
}

void	ft_menubonus(void)
{
	ft_printf("##########################################\n");
	ft_printf("#\033[0;31m                 ERROR                  \033[0m#\n");
	ft_printf("##########################################\n");
	ft_printf("# Please enter one of the letters bellow #\n");
	ft_printf("#\033[0;32m     For Mandelbrot  	==>   M or m     \033[0m#\n");
	ft_printf("#\033[0;33m     For Julia		==>   J or j     \033[0m#\n");
	ft_printf("#\033[0;34m     For Burning Ship	==>   B or b     \033[0m#\n");
	ft_printf("##########################################\n");
}

void	my_mlx_pixel_put(t_fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length) + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	map(t_map *maping)
{
	double	r;

	r = (maping->x - maping->min_in) * (maping->max_out - maping->min_out) / \
		(maping->max_in - maping->min_in) + maping->min_out;
	return (r);
}
