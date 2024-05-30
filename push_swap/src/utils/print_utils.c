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

void	print_buffer(t_stack *s)
{
	int	i;

	i = 0;
	if (s->entries == 0)
		return ;
	while (i != s->entries)
	{
		ft_printf("%d", s->content[s->head + i]);
		ft_printf("\n");
		i++;
	}
}

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