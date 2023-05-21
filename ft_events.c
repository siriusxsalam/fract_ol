/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:05:08 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 03:56:39 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fract *data)
{
	if (keycode == 53)
		(mlx_clear_window(data->mlx, data->mlx_win), exit(1));
	else if (keycode == 69)
		data->zoom /= 1.05;
	else if (keycode == 78)
		data->zoom *= 1.05;
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->i == 1)
		mandelbrot_helper1(data);
	else if (data->i == 2)
		julia_helper1(data);
	return (0);
}

int	ft_close(t_fract *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	exit(1);
}
