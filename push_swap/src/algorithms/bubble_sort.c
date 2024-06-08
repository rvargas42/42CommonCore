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
	if (get_index(smallest(a), a) == a->head)
		push_stack(a, b);
	else
		smallest_to_top(a);
	if (b_arr[b->head] < b_arr[b->tail])
		rotate_stack(b);
	if (b_arr[b->head] < b_arr[b->head + 1])
		swap_stack(b);
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}