/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:00:40 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/17 11:35:53 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_str(t_print *p)
{
	char	*str;
	int		len;

	str = va_arg(p->vars, char *);
	if (str == NULL)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		p->tlen += 6;
		return (0);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	p->tlen += len;
	return (len);
}
