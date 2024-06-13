/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_devide.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:25:27 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/12 11:40:23 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


static void	push_range(t_stack *src, t_stack *dst)
{
	int	*dst_arr;
	int	*src_arr;
	int	range;
	int	ref;

	src_arr = src->content;
	range = 1;
	ref = src_arr[src->head];
	while (ref < src_arr[src->head + range])
	{
		ref = src_arr[src->head + range];
		range++;
	}
	if (range != 1)
		repeat_push(range - 1, src, dst);
}

static void	push_opt_min(t_stack *src, t_stack *dst, int min) //TODO: revisar
{
	if (min == INT_MIN)
		min = smallest(src);
	number_to_top(src, min);
	push_stack(src, dst);
}

void	insertion_sort_divide(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;
	int		opt;

	a = ab_stacks->a;
	a_arr = a->content;
	b = ab_stacks->b;
	b_arr = b->content;
	if (b->entries == 0)
		repeat_push(a->entries, a, b);
	if (b_arr[b->head] < b_arr[b->tail])
		rotate_stack(b);
	if (b_arr[b->head] < b_arr[b->head + 1])
		swap_stack(b);
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}