/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsetup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:32:57 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/20 11:36:02 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printsetup(va_list ap, char setup, int *cnt)
{
	if (setup == '%')
		ft_putchar('%', cnt);
	else if (setup == 'p')
		ft_putpointer(va_arg(ap, unsigned long int), cnt);
	else if (setup == 'u')
		ft_putunsg(va_arg(ap, unsigned int), cnt);
	else if (setup == 'd' || setup == 'i')
		ft_putnbr(va_arg(ap, int), cnt);
	else if (setup == 'c')
		ft_putchar(va_arg(ap, int), cnt);
	else if (setup == 's')
		ft_putstr(va_arg(ap, char *), cnt);
	else if (setup == 'x')
		ft_putluhex(va_arg(ap, unsigned int), cnt, "0123456789abcdef");
	else if (setup == 'X')
		ft_putluhex(va_arg(ap, unsigned int), cnt, "0123456789ABCDEF");
	else
		ft_putchar(setup, cnt);
}
