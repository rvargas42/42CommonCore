/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:38:35 by ravargas          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:51 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	catstr = (char *) malloc(sizeof(char) * len);
	if (!catstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		catstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		catstr[i + j] = s2[j];
		j++;
	}
	catstr[i + j] = '\0';
	return (catstr);
}
