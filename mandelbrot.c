/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:21:55 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 03:05:04 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_helper2(t_fract *mandl, t_map *mapin)
{
	mapin->x = mandl->x0;
	mapin->min_in = mandl->x1;
	mapin->max_in = mandl->y1;
	mandl->a = map(mapin) * mandl->zoom;
	mapin->min_in = mandl->x2;
	mapin->max_in = mandl->y2;
	mapin->x = mandl->y0;
	mandl->b = map(mapin) * mandl->zoom;
	mandl->ca = mandl->a;
	mandl->cb = mandl->b;
	mandl->iter = 0;
	while ((mandl->a * mandl->a) + (mandl->b * mandl->b) <= 4 \
			&& mandl->iter < mandl->max_iter)
	{
		mandl->aa = (mandl->a * mandl->a) - (mandl->b * mandl->b);
		mandl->bb = 2 * mandl->a * mandl->b;
		mandl->a = mandl->aa + mandl->ca;
		mandl->b = mandl->bb + mandl->cb;
		mandl->iter++;
	}
	if (mandl->iter == mandl->max_iter)
		my_mlx_pixel_put(mandl, mandl->x0, mandl->y0, 0x000000);
	else
		my_mlx_pixel_put(mandl, mandl->x0, mandl->y0, \
		mandl->color * mandl->iter);
}

void	mandelbrot_helper1(t_fract *mandl)
{
	t_map	mapin;

	mapin.min_out = -2;
	mapin.max_out = 2;
	mandl->y0 = 0;
	while (mandl->y0 < 500)
	{
		mandl->x0 = 0;
		while (mandl->x0 < 500)
		{
			mandelbrot_helper2(mandl, &mapin);
			mandl->x0++;
		}
		mandl->y0++;
	}
	mlx_put_image_to_window(mandl->mlx, mandl->mlx_win, mandl->img, 0, 0);
	mlx_key_hook(mandl->mlx_win, key_hook, mandl);
	mlx_hook(mandl->mlx_win, 17, 0, ft_close, mandl);
	mlx_loop(mandl->mlx);
}

int	mandelbrot(t_fract mandl)
{
	if (mandl.ac == 2)
	{
		mandl.max_iter = 100;
		mandl.x1 = 0;
		mandl.y1 = 500;
		mandl.x2 = 0;
		mandl.y2 = 500;
		mandl.pa = 0;
		mandl.pb = 0;
		mandl.zoom = 1;
		mandl.color = 0x000d00;
		mandl.mlx = mlx_init();
		mandl.img = mlx_new_image(mandl.mlx, 500, 500);
		mandl.addr = mlx_get_data_addr(mandl.img, &mandl.bits_per_pixel,
				&mandl.line_length, &mandl.endian);
		mandl.mlx_win = mlx_new_window(mandl.mlx, 500, 500, "Mandelbrot");
		mandelbrot_helper1(&mandl);
	}
	else
		ft_menu();
	return (0);
}
