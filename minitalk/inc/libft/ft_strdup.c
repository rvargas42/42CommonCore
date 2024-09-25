/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:37 by ravargas          #+#    #+#             */
/*   Updated: 2023/09/26 14:37:49 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p_cpy_s1;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *) s1);
	p_cpy_s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!p_cpy_s1)
		return (NULL);
	p_cpy_s1 = ft_memcpy(p_cpy_s1, s1, len + 1);
	return ((char *)p_cpy_s1);
}
