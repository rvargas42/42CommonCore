/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:24:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/25 11:22:39 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while (n > 0)
	{
		ps[i] = '\0';
		i++;
		n--;
	}
}
