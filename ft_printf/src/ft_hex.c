/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:08:13 by ravargas          #+#    #+#             */
/*   Updated: 2023/11/11 14:21:37 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_puthex(unsigned int n)
{
	if (n <= 16)
	{
		if (n == 16)
			write(1, "10", 2);
		else
			write(1, &HEXLOWER[n], 1);
	}
	else
	{
		ft_puthex(n / 16);
		write(1, &HEXLOWER[n % 16], 1);
	}
}

static int	hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_hex(t_print *p)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(p->vars, unsigned int);
	if (arg == 0)
	{
		p->tlen += write(1, "0", 1);
		return (0);
	}
	ft_puthex(arg);
	len = hexlen(arg);
	p->tlen += len;
	return (len);
}
