/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:31:50 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/08 15:19:21 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	smallest(t_stack *s)
{
	int	i;
	int	comp;
	int	temp;

	i = 1;
	temp = s->content[s->head];
	while ((comp = s->content[s->head + i]))
	{
		if (temp > comp)
			temp = comp;
		i++;
	}
	return (temp);
}

int	push_cost(int index, t_stack *s)
{
	int	cost;
	int	midpoint;

	midpoint = s->head + ((s->entries) / 2);
	if (index > midpoint)
		return (s->tail - index + 1);
	if (s->entries == 0 || index < s->head)
		return (0);
	else
		return (index - s->head);
}

int	itarget_cost(int index_a, int index_b, t_stacks *ab_stacks)
{
	int	icost;
	int	a;
	int	b;

	a = push_cost(index_a, ab_stacks->a);
	b = push_cost(index_b, ab_stacks->b);
	icost = a + b;
	return (icost);
}
