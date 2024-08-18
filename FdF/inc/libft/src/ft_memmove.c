/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:32:29 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:10 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	unsigned const char	*p_src;

	if (dst < src)
		return (ft_memcpy(dst, src, n));
	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	if (!n || dst == src)
		return (dst);
	while (n--)
		p_dst[n] = p_src[n];
	return (dst);
}
