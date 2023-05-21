/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:33:08 by hasalam           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:49 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_norm
{
	va_list	ap;
	int		cnt;
}	t_norm;

int		ft_printf(const char *setup, ...);
void	ft_putchar(char c, int *cnt);
void	ft_putluhex(unsigned int nb, int *cnt, char *base);
void	ft_putnbr(int nb, int *cnt);
void	ft_putpointer(unsigned long int nb, int *cnt);
void	ft_putstr(char *str, int *cnt);
void	ft_putunsg(unsigned int nb, int *cnt);
void	printsetup(va_list ap, char setup, int *cnt);
int		ft_printf_bonus(t_norm *norm, const char *setup, int i);

#endif