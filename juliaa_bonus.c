/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaa_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:07:09 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 03:37:23 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	juliabonus_helper2(t_fract *juls, t_map *mapin)
{
	mapin->x = juls->x0;
	mapin->min_in = juls->x1;
	mapin->max_in = juls->y1;
	juls->a = map(mapin) * juls->zoom + juls->pa;
	mapin->x = juls->y0;
	mapin->min_in = juls->x2;
	mapin->max_in = juls->y2;
	juls->b = map(mapin) * juls->zoom + juls->pb;
	juls->iter = 0;
	while ((juls->a * juls->a) + (juls->b * juls->b) <= 4 \
			&& juls->iter < juls->max_iter)
	{
		juls->aa = (juls->a * juls->a) - (juls->b * juls->b);
		juls->bb = (2 * juls->a * juls->b);
		juls->a = juls->aa + juls->ca;
		juls->b = juls->bb + juls->cb;
		juls->iter++;
	}
	if (juls->iter == juls->max_iter)
		my_mlx_pixel_put(juls, juls->x0, juls->y0, 0x000000);
	else
		my_mlx_pixel_put(juls, juls->x0, juls->y0, juls->color * juls->iter);
}

void	juliabonus_helper1(t_fract *juls)
{
	t_map	mapin;

	mapin.min_out = -2;
	mapin.max_out = 2;
	juls->y0 = 0;
	while (juls->y0 <= 500)
	{
		juls->x0 = 0;
		while (juls->x0 <= 500)
		{
			juliabonus_helper2(juls, &mapin);
			juls->x0++;
		}
		juls->y0++;
	}
	mlx_put_image_to_window(juls->mlx, juls->mlx_win, juls->img, 0, 0);
	mlx_key_hook(juls->mlx_win, keybonus_hook, juls);
	mlx_hook(juls->mlx_win, 17, 0, ft_close_bonus, juls);
	mlx_hook(juls->mlx_win, 4, 0, mscroolbonus_hook, juls);
	mlx_loop(juls->mlx);
}

void	parss_helper(char *str, t_parss *p)
{
	p->j = 0;
	p->i = 0;
	p->f = 0;
	p->r1 = 0;
	p->r2 = 0;
	while (str[p->i] == '\t' || str[p->i] == '\r' || str[p->i] == '\v'
		|| str[p->i] == '\f' || str[p->i] == '\n' || str[p->i] == ' ')
		p->i++;
	if (!str[p->i])
		(ft_menubonus(), exit(1));
	while (str[p->i] && str[p->i] != '.')
		p->i++;
	if (str[p->i] == '.')
		p->f = 1;
	if (!str[p->i + 1] && (str[p->i + 1] < 48 || str[p->i + 1] > 57)
		&& p->f == 1)
		(ft_menubonus(), exit(1));
	p->i++;
	if ((str[p->j] == '+' || str[p->j] == '-') && (str[p->j + 1] >= 48 \
		&& str[p->j + 1] <= 57))
	{
		if (str[p->j] == '-')
			p->n = p->n * -1;
		p->j++;
	}
}

double	parssing(char *str)
{
	t_parss	p;

	p.n = 1;
	parss_helper(str, &p);
	while (str[p.j] && str[p.j] != '.')
	{
		if (str[p.j] >= 48 && str[p.j] <= 57)
			p.r1 = (p.r1 * 10) + (str[p.j] - 48);
		else
			(ft_menubonus(), exit(1));
		p.j++;
	}
	p.j = 0;
	while (str[p.i] && p.f == 1)
	{
		if (str[p.i] >= 48 && str[p.i] <= 57)
			p.r2 = (p.r2 * 10) + (str[p.i] - 48);
		else
			(ft_menubonus(), exit(1));
		p.i++;
		p.j++;
	}
	p.t = p.r2 * pow(10, -p.j);
	p.t = p.t + p.r1;
	return (p.t * p.n);
}

int	julia_bonus(t_fract juls)
{
	juls.max_iter = 100;
	if (juls.ac == 4)
	{
		juls.ca = parssing(juls.av[2]);
		juls.cb = parssing(juls.av[3]);
	}
	else
	{
		juls.ca = -0.8;
		juls.cb = 0.156;
	}
	juls.x1 = 0;
	juls.y1 = 500;
	juls.x2 = 0;
	juls.y2 = 500;
	juls.zoom = 1;
	juls.color = 0x000d00;
	juls.mlx = mlx_init();
	juls.img = mlx_new_image(juls.mlx, 500, 500);
	juls.addr = mlx_get_data_addr(juls.img, &juls.bits_per_pixel,
			&juls.line_length, &juls.endian);
	juls.mlx_win = mlx_new_window(juls.mlx, 500, 500, "Julia");
	juliabonus_helper1(&juls);
	return (0);
}
