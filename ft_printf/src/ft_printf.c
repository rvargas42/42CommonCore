/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:23:20 by ravargas          #+#    #+#             */
/*   Updated: 2023/11/11 14:58:08 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	isflag(char const s)
{
	char	*f;
	int		i;

	f = FORMATS;
	i = 0;
	while (*f != '\0')
	{
		if (s != *f)
			i = 0;
		else
			return (1);
		f++;
	}
	return (i);
}

static void	ft_check_format(char const *s, t_print *p, int i)
{
	if (s[i] == 'c')
		ft_pchar(p);
	else if (s[i] == 's')
		ft_str(p);
	else if (s[i] == 'p')
		ft_pointr(p);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_number(p);
	else if (s[i] == 'u')
		ft_unsigned(p);
	else if (s[i] == 'X')
		ft_hexupp(p);
	else if (s[i] == 'x')
		ft_hex(p);
}

int	ft_iter_s(char const *s, t_print *p)
{
	int	i;
	int	check_err;

	i = 0;
	check_err = 0;
	if (!s || !p)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (ft_strchr(FORMATS, s[i]))
				ft_check_format(s, p, i);
			else if (s[i] == '%')
				ft_wrt_percent(p);
		}
		else
			p->tlen += write(1, &s[i], 1);
		i++;
	}
	return (p->tlen);
}

int	ft_printf(char const *s, ...)
{
	t_print		*p;
	int			tlen;

	tlen = 0;
	p = (t_print *)malloc(sizeof(t_print));
	if (!p || !s)
	{
		free(p);
		return (-1);
	}
	ft_init_struct(p);
	va_start(p->vars, s);
	ft_iter_s(s, p);
	va_end(p->vars);
	free(p);
	return (p->tlen);
}
