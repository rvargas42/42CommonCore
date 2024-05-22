/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:31:00 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:21:58 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *)s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)&p_s[i]);
		i++;
	}
	return (NULL);
}
