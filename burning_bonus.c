/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:31:54 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 04:00:50 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	burnshipbonus_helper2(t_fract *burn, t_map *mapin)
{
	mapin->x = burn->x0;
	mapin->min_in = burn->x1;
	mapin->max_in = burn->y1;
	burn->a = map(mapin) * burn->zoom + burn->pa;
	mapin->min_in = burn->x2;
	mapin->max_in = burn->y2;
	mapin->x = burn->y0;
	burn->b = map(mapin) * burn->zoom + burn->pb;
	burn->ca = burn->a;
	burn->cb = burn->b;
	burn->iter = 0;
	while ((burn->a * burn->a) + (burn->b * burn->b) <= 4 \
		&& burn->iter < burn->max_iter)
	{
		burn->aa = (burn->a * burn->a) - (burn->b * burn->b);
		burn->bb = 2 * fabs(burn->a * burn->b);
		burn->a = burn->aa + burn->ca;
		burn->b = burn->bb + burn->cb;
		burn->iter++;
	}
	if (burn->iter == burn->max_iter)
		my_mlx_pixel_put(burn, burn->x0, burn->y0, 0x000000);
	else
		my_mlx_pixel_put(burn, burn->x0, burn->y0, burn->color * burn->iter);
}

void	burnshipbonus_helper1(t_fract *burn)
{
	t_map	mapin;

	mapin.min_out = -2;
	mapin.max_out = 2;
	burn->y0 = 0;
	while (burn->y0 <= 500)
	{
		burn->x0 = 0;
		while (burn->x0 <= 500)
		{
			burnshipbonus_helper2(burn, &mapin);
			burn->x0++;
		}
		burn->y0++;
	}
	mlx_put_image_to_window(burn->mlx, burn->mlx_win, burn->img, 0, 0);
	mlx_hook(burn->mlx_win, 17, 0, ft_close_bonus, burn);
	mlx_key_hook(burn->mlx_win, keybonus_hook, burn);
	mlx_hook(burn->mlx_win, 4, 0, mscroolbonus_hook, burn);
	mlx_loop(burn->mlx);
}

int	burning_ship_bonus(t_fract burn)
{
	if (burn.ac == 2)
	{
		burn.max_iter = 100;
		burn.x1 = 0;
		burn.y1 = 500;
		burn.x2 = 0;
		burn.y2 = 500;
		burn.pa = 0;
		burn.pb = 0;
		burn.zoom = 1;
		burn.color = 0x000d00;
		burn.mlx = mlx_init();
		burn.img = mlx_new_image(burn.mlx, 500, 500);
		burn.addr = mlx_get_data_addr(burn.img, &burn.bits_per_pixel,
				&burn.line_length, &burn.endian);
		burn.mlx_win = mlx_new_window(burn.mlx, 500, 500, "Burning Ship");
		burnshipbonus_helper1(&burn);
	}
	else
		ft_menubonus();
	return (0);
}
