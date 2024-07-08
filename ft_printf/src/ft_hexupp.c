/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:08:32 by ravargas          #+#    #+#             */
/*   Updated: 2023/11/09 11:42:47 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_puthexupp(unsigned int n)
{
	if (n <= 16)
	{
		if (n == 16)
			write(1, "10", 2);
		else
			write(1, &HEXUPPER[n], 1);
	}
	else
	{
		ft_puthexupp(n / 16);
		write(1, &HEXUPPER[n % 16], 1);
	}
}

static	int	hexupplen(unsigned int n)
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

int	ft_hexupp(t_print *p)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(p->vars, unsigned int);
	if (arg == 0)
	{
		p->tlen += write(1, "0", 1);
		return (0);
	}
	ft_puthexupp(arg);
	len = hexupplen(arg);
	p->tlen += len;
	return (len);
}
