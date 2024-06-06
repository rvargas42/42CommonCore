/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:25:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 20:50:30 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	bubble_sort(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;
	
	a = ab_stacks->a;
	b = ab_stacks->b;
	if (a->entries >= 2)
	{	
		if (a->content[a->head] < a->content[a->head + 1])
			push_stack(a, b);
		if (a->content[a->head] > a->content[a->head + 1])
			swap_stack(a);
		if (b->content[b->head] < b->content[b->tail])
			rotate_stack(b);
	}
	else
		repeat_push(b->entries, b, a);
}