/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:09:13 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/17 11:35:55 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int	usignedlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*usigneditoa(unsigned int n)
{
	char	*num;
	int		len;

	len = usignedlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_unsigned(t_print *p)
{
	unsigned int	arg;
	char			*num;
	int				len;

	arg = va_arg(p->vars, unsigned int);
	if (arg == 0)
	{
		p->tlen += write(1, "0", 1);
		return (0);
	}
	num = usigneditoa(arg);
	len = usignedlen(arg);
	ft_putstr_fd(num, 1);
	free(num);
	p->tlen += len;
	return (len);
}
