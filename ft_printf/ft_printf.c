/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:26:56 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/04 17:41:46 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(t_norm *norm, const char *setup)
{
	int	i;

	i = -1;
	while (setup[++i])
	{
		if (setup[i] == '%' && setup[i + 1] == '\0')
		{
			i++;
			break ;
		}
		if (setup[i] == '%')
		{
			i++;
			printsetup(norm->ap, setup[i], &norm->cnt);
		}
		else
			ft_putchar(setup[i], &norm->cnt);
	}
	return (norm->cnt);
}

int	ft_printf(const char *setup, ...)
{
	t_norm	norm;

	if (write(1, "", 1) == -1)
		return (-1);
	va_start(norm.ap, setup);
	norm.cnt = 0;
	norm.cnt = helper(&norm, setup);
	va_end(norm.ap);
	return (norm.cnt);
}
