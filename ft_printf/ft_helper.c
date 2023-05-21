/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:27:04 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/18 16:16:29 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putluhex(unsigned int nb, int *cnt, char *base)
{
	if (nb < 16 && nb >= 0)
		ft_putchar(base[nb], cnt);
	else
	{
		ft_putluhex(nb / 16, cnt, base);
		ft_putchar(base[nb % 16], cnt);
	}
}

void	ft_putnbr(int nb, int *cnt)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-', cnt);
	}
	if (nbr < 10)
		ft_putchar(nbr + '0', cnt);
	else
	{
		ft_putnbr(nbr / 10, cnt);
		ft_putchar((nbr % 10) + '0', cnt);
	}
}

void	ft_putpointer(unsigned long int nb, int *cnt)
{
	ft_putchar('0', cnt);
	ft_putchar('x', cnt);
	ft_putluhex(nb, cnt, "0123456789abcdef");
}

void	ft_putstr(char *str, int *cnt)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	*cnt += i;
	write(1, str, i);
}

void	ft_putunsg(unsigned int nb, int *cnt)
{
	if (nb < 10)
		ft_putchar(nb + '0', cnt);
	else
	{
		ft_putunsg(nb / 10, cnt);
		ft_putchar((nb % 10) + '0', cnt);
	}
}
