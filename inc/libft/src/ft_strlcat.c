/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:39:00 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:46 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen((char *)src);
	if (!dst && dstsize == 0)
		return (slen);
	d = ft_strlen((char *)dst);
	dlen = d;
	if (dstsize <= dlen)
		return (dstsize + slen);
	s = 0;
	while (src[s] && d + 1 < dstsize)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = 0;
	return (dlen + slen);
}
