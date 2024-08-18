/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:33:01 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:14 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;
	size_t			i;

	pb = (unsigned char *) b;
	c = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		pb[i] = c;
		i++;
	}
	return ((void *) pb);
}
