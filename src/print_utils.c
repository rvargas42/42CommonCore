/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:57:27 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/22 12:14:24 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_unordered(int	*nums)
{
	int		i;
	char	c;

	i = 0;
	while (nums[i++])
	{
		c = nums[i] - 48;
		write(1, &c, 1);
	}
}