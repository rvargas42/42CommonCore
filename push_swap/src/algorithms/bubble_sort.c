/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:25:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/07 08:51:06 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	smallest_to_top(t_stack *s)
{
	int	*arr;
	int	small_index;
	int	cost;

	arr = s->content;
	small_index = smallest(arr);
	cost = push_cost(small_index, s);
	if (small_index <= mid_point)
		repeat_rotate(cost, s);
	if (small_index > mid_point)
		repeat_rvrotate(cost, s);
}

void	bubble_sort(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;
	
	a = ab_stacks->a;
	a_arr = a->content;
	b = ab_stacks->b;
	b_arr = b->content;
	if (a->entries > 1)
	{
		if (smallest(a) > a->head)
			smallest_to_top(a);
		if (a_arr[a->head] > a_arr[b->head])
			push_stack(a, b);
		if (b_arr[b->head] < b_arr[b->tail])
			rotate_stack(b);
		if (a_arr[a->head] > a_arr[a->tail])
			rotate_stack(a);
		if (b_arr[b->head] < b_arr[b->head + 1])
			swap_stack(b);
		if (a_arr[a->head] > a_arr[a->head + 1])
			swap_stack(a);
	}
	else
		repeat_push(b->entries, b, a);
}