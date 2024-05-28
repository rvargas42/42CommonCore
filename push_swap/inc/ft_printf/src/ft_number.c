/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:02:37 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/17 11:35:41 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putnbr(int n, t_print *p)
{
	char	c;

	if (n == -2147483648)
		p->tlen += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			p->tlen += write(1, "-", 1);
			n = -n;
			ft_putnbr(n, p);
		}
		else if (n < 10)
		{
			c = n + '0';
			p->tlen += write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10, p);
			c = (n % 10) + '0';
			p->tlen += write(1, &c, 1);
		}
	}
}

void	ft_number(t_print *p)
{
	int	d;
	int	n;
	int	len;

	len = 0;
	d = va_arg(p->vars, int);
	n = d;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	ft_putnbr(d, p);
}
