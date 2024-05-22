/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:08:50 by ravargas          #+#    #+#             */
/*   Updated: 2023/11/09 11:48:40 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_ptr_address(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_ptr_address(ptr / 16);
		ft_ptr_address(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

static	int	ft_ptraddress_len(unsigned long ptr, t_print *p)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr >>= 4;
		len++;
	}
	if (len == 0)
		return (3);
	p->tlen += write(1, "0x", 2);
	return (len);
}

int	ft_pointr(t_print *p)
{
	unsigned long	args;
	int				len;

	args = va_arg(p->vars, unsigned long);
	len = ft_ptraddress_len(args, p);
	if (len == 3)
	{
		p->tlen += write(1, "0x0", 3);
		return (0);
	}
	ft_ptr_address(args);
	p->tlen += len;
	return (len);
}
