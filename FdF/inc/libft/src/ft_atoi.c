/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:25:51 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/16 20:06:40 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	is_bigger(long long int n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (-1);
	return (0);
}

long int	ft_atoi(const char	*str)
{
	int						i;
	int						neg;
	unsigned long long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
		if (is_bigger(num * neg) == -1)
			return (-1);
	}
	return (num * neg);
}