/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:31:59 by ravargas          #+#    #+#             */
/*   Updated: 2023/09/27 17:35:12 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (!dst && !src)
		return (NULL);
	p_dst = (unsigned char *) dst;
	p_src = (const unsigned char *) src;
	while (n-- > 0)
	{
		*(p_dst++) = *(p_src++);
	}
	return (dst);
}
