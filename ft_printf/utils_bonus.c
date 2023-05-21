/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:32:46 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/19 00:43:26 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_checker(const char *setup)
{
	int	i;

	i = 1;
	while (setup[i] != 'x' && setup[i] != 'X' && setup[i] != 'd' && \
		setup[i] != 'i')
		i++;
	return (setup[i]);
}

static void	ft_putoprator(t_norm *norm, char setup, char check, char op)
{
	if (op == '#')
	{
		ft_putchar('0', &norm->cnt);
		if (check == 'x')
			ft_putchar('x', &norm->cnt);
		else if (check == 'X')
			ft_putchar('X', &norm->cnt);
		printsetup(norm->ap, setup, &norm->cnt);
	}
	else if (op == '+')
	{
		ft_putchar('+', &norm->cnt);
		printsetup(norm->ap, setup, &norm->cnt);
	}
	else if (op == ' ')
	{
		ft_putchar(' ', &norm->cnt);
		printsetup(norm->ap, setup, &norm->cnt);
	}
}

static int	helper1(t_norm *norm, const char *setup, char check, int i)
{
	int	n;

	n = 0;
	while (setup[i] != 'x' && setup[i] != 'X')
	{
		if (setup[i] == '#')
			n = 1;
		i++;
	}
	if ((setup[i] == 'x' || setup[i] == 'X') && n == 1)
		ft_putoprator(norm, setup[i], check, '#');
	else
		printsetup(norm->ap, setup[i], &norm->cnt);
	return (i);
}

static int	helper2(t_norm *norm, const char *setup, char check, int i)
{
	int	n;
	int	s;

	n = 0;
	s = 0;
	while (setup[i] != 'd' && setup[i] != 'i')
	{
		if (setup[i] == '+')
			n = 1;
		else if (setup[i] == ' ')
			s = 1;
		i++;
	}
	if ((setup[i] == 'd' || setup[i] == 'i') && n == 1)
		ft_putoprator(norm, setup[i], check, '+');
	else if ((setup[i] == 'd' || setup[i] == 'i') && s == 1)
		ft_putoprator(norm, setup[i], check, ' ');
	else
		printsetup(norm->ap, setup[i], &norm->cnt);
	return (i);
}

int	ft_printf_bonus(t_norm *norm, const char *setup, int i)
{
	char	check;

	check = ft_checker(setup);
	if (check == 'x' || check == 'X')
		i = helper1(norm, setup, check, i);
	else if (check == 'd' || check == 'i')
		i = helper2(norm, setup, check, i);
	return (i);
}
