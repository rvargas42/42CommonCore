/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:25:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 14:24:23 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


static void	push_range(t_stack *src, t_stack *dst)
{
	int	*dst_arr;
	int	*src_arr;
	int	range;

	dst_arr = dst->content;
	src_arr = src->content;
	range = 0;
	while (src_arr[src->head + range] < dst_arr[dst->head])
		range++;
	while (range-- > 0)
		push_stack(src, dst);
}

void	insertion_sort(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;

	a = ab_stacks->a;
	a_arr = a->content;
	b = ab_stacks->b;
	b_arr = b->content;
	push_range(a, b);
	if (a_arr[a->head] > a_arr[a->head + 1])
		swap_stack(a);
	if (get_index(smallest(a), a) == a->head)
		push_stack(a, b);
	else
		index_to_top(a, smallest(a));
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}