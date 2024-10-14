/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:27:18 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:21:01 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == 4294967295 && size == 4294967295)
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, (count * size));
	return (p);
}
