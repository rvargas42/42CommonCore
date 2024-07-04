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
	while (i < s->entries)
	{
		ft_printf("%d", s->content[s->head + i]);
		ft_printf("\n");
		i++;
	}
}

void	print_unordered(int	*nums, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(nums[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	print_stacks(t_stacks *stacks)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (i != stacks->a->max_size)
	{
		if (stacks->a->head <= i)
			a = stacks->a->content[i];
		if (stacks->b->head <= i)
			b = stacks->b->content[i];
		if (stacks->a->head > i || stacks->a->entries == 0)
			a = 0;
		if (stacks->b->head > i || stacks->b->entries == 0)
			b = 0;
		ft_printf("|	%d	|	%d	|\n", a, b);
		i++;
	}
	ft_printf("\n");
}
