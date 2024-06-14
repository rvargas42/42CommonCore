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
	int	ref;

	dst_arr = dst->content;
	src_arr = src->content;
	range = 1;
	ref = src_arr[src->head];
	while (ref < src_arr[src->head + range])
	{
		ref = src_arr[src->head + range];
		range++;
	}
	if (range <= 2)
		return ;
	else
		repeat_push(range - 1, src, dst);
}

void cluster_arange(t_stack *src, t_stack *dst, int range) //TODO: takes range and sorts it to later push to b
{
	return ;
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
	if (get_index(smallest(a), a) == a->head)
		push_stack(a, b);
	else
		number_to_top(a, smallest(a));
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}