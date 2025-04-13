/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:07:33 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/11 12:17:17 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_atoi_hex(char *num)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	if (num == NULL || ft_strlen(num) <= 2)
		return (0);
	while (num[i])
	{
		result *= 16;
		if (num[i] >= '0' && num[i] <= '9')
			result += num[i] - '0';
		if (num[i] >= 'a' && num[i] <= 'f')
			result += num[i] - 'a' + 10;
		if (num[i] >= 'A' && num[i] <= 'F')
			result += num[i] - 'A' + 10;
		i++;
	}
	return (result);
}
