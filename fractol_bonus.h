/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:33:04 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/20 04:01:14 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct n_hook
{
	double	oldx;
	double	oldy;
	double	newx;
	double	newy;
}	t_hook;

typedef struct n_map
{
	double	x;
	double	min_in;
	double	max_in;
	double	min_out;
	double	max_out;
}	t_map;

typedef struct n_parss
{
	double	t;
	int		i;
	int		j;
	int		n;
	int		r1;
	int		r2;
	int		f;
}	t_parss;

typedef struct n_fract
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	ca;
	double	cb;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	zoom;
	double	pa;
	double	pb;
	int		color;
	int		i;
	int		iter;
	int		max_iter;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		ac;
	char	**av;
}	t_fract;

int		julia_bonus(t_fract juls);
void	ft_menubonus(void);
void	my_mlx_pixel_put(t_fract *data, int x, int y, int color);
double	map(t_map *maping);
int		keybonus_hook(int keycode, t_fract *data);
int		ft_close_bonus(t_fract *data);
int		burning_ship_bonus(t_fract burn);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		fractal_bonus(int i, int argc, char **argv);
int		mandelbrot_bonus(t_fract mandl);
void	juliabonus_helper1(t_fract *juls);
void	mandelbrotbonus_helper1(t_fract *mandl);
void	burnshipbonus_helper1(t_fract *burn);
int		mscroolbonus_hook(int mousecode, int x, int y, t_fract *data);

#endif