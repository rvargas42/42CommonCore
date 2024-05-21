/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:33:01 by ravargas          #+#    #+#             */
/*   Updated: 2023/09/26 14:33:21 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
