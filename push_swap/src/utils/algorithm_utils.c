/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:40:48 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/07 09:28:46 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	smallest(int *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s[i];
	while (s[i++])
	{
		if (temp > s[i])
			temp = s[i];
	}
	return (i);
}

int	mid_point(int head, int tail, int entries)
{
	int	mid_point;

	mid_point = head + ((tail + 1 - head) / 2);
	return (mid_point);
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

int	push_cost(int index, t_stack *s)
{
	int	cost;
	int	midpoint;

	midpoint = mid_point(s->head,s->tail,s->entries);
	if (s->entries == 0 || index < s->head)
		return (0);
	else
		return (index - s->head + 1);
}