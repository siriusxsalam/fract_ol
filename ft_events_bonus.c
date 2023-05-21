/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:47:31 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 04:17:27 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	keyhookbonus_helper(int keycode, t_fract *data)
{
	if (keycode == 69)
		data->zoom /= 1.05;
	else if (keycode == 78)
		data->zoom *= 1.05;
	else if (keycode == 7)
		data->color += (data->color << 4) + 45;
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->i == 1)
		mandelbrotbonus_helper1(data);
	else if (data->i == 2)
		juliabonus_helper1(data);
	else if (data->i == 3)
		burnshipbonus_helper1(data);
}

int	keybonus_hook(int keycode, t_fract *data)
{
	if (keycode == 53)
		(mlx_clear_window(data->mlx, data->mlx_win), exit(1));
	else if (keycode == 124)
	{
		data->x1 -= 10;
		data->y1 -= 10;
	}
	else if (keycode == 123)
	{
		data->x1 += 10;
		data->y1 += 10;
	}
	else if (keycode == 126)
	{
		data->x2 += 10;
		data->y2 += 10;
	}
	else if (keycode == 125)
	{
		data->x2 -= 10;
		data->y2 -= 10;
	}
	keyhookbonus_helper(keycode, data);
	return (0);
}

void	mscroolhookbonus_helper(int mousecode, t_fract *data, t_hook *h, int f)
{
	if (f == 0)
	{
		if (mousecode == 5)
		{
			data->zoom /= 1.5;
			data->max_iter *= 1.04;
		}
		else if (mousecode == 4)
		{
			data->zoom *= 1.5;
			data->max_iter /= 1.04;
		}
	}
	else
	{
		data->pa += h->oldx - h->newx;
		data->pb += h->oldy - h->newy;
		mlx_clear_window(data->mlx, data->mlx_win);
		if (data->i == 1)
			mandelbrotbonus_helper1(data);
		else if (data->i == 2)
			juliabonus_helper1(data);
		else if (data->i == 3)
			burnshipbonus_helper1(data);
	}
}

int	mscroolbonus_hook(int mousecode, int x, int y, t_fract *data)
{
	t_map	mapin;
	t_hook	h;

	if (x <= 500 && x >= 0 && y <= 500 && y >= 0)
	{
		mapin.min_in = 0;
		mapin.max_in = 500;
		mapin.min_out = -2;
		mapin.max_out = 2;
		mapin.x = x;
		h.oldx = map(&mapin) * data->zoom;
		mapin.x = y;
		h.oldy = map(&mapin) * data->zoom;
		mscroolhookbonus_helper(mousecode, data, &h, 0);
		mapin.x = x;
		h.newx = map(&mapin) * data->zoom;
		mapin.x = y;
		h.newy = map(&mapin) * data->zoom;
		mscroolhookbonus_helper(mousecode, data, &h, 1);
	}
	return (0);
}

int	ft_close_bonus(t_fract *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	exit(1);
}
