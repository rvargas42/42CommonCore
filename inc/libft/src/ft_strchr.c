/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:11 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/14 13:20:47 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	str;

	str = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == str)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == str)
		return ((char *)(s + i));
	return (0);
}
