/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:57:27 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 12:59:50 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_unordered(int	*nums)
{
	int	i;
	int	c;

	i = 0;
	while (nums[i])
	{
		c = nums[i];
		ft_putnbr_fd(nums[i], 1);
		write(1, "\n", 2);
		i++;
	}
}