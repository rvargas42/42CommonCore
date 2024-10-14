/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:03:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/17 11:36:00 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_print	*ft_init_struct(t_print *tab)
{
	tab->tlen = 0;
	tab->fmw = 0;
	tab->dash = 0;
	tab->is_zero = 0;
	tab->point = 0;
	tab->space = 0;
	tab->hashtag = 0;
	tab->plus = 0;
	tab->perc = 0;
	return (tab);
}

int	ft_set_pinfo(char const *s, t_print *p, int i)
{
	while (isflag(s[i]) == 1)
	{
		if (s[i] == '-')
			p->dash = 1;
		if (s[i] == '0')
			p->is_zero = 1;
		if (s[i] == '.')
			p->point = 1;
		if (s[i] == '*' || s[i] == '?')
			p->fmw = 1;
		if (s[i] == '#')
			p->hashtag = 1;
		if (s[i] == ' ')
			p->space = 1;
		if (s[i] == '+')
			p->plus = 1;
		i++;
	}
	return (i);
}
