/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:20 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 13:36:03 by ravargas         ###   ########.fr       */
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
	if (range == 1)
		return ;
	else
		repeat_push(range - 1, src, dst);
}

void	mean_sep(t_stacks *ab)
{
	int	mean;
	int	n;

	n = 0;
	mean = stack_mean(ab->a);
	//ft_printf("mean: %d\n", mean);
	while (n < ab->a->entries)
	{
		number_to_top(ab->a, closest_down(ab->a, mean));
		if (ab->a->content[ab->a->head + n] < mean)
			push_stack(ab->a, ab->b);
		n++;
	}
}


void	quick_sort(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;
	int		sub_arr_len;

	a = ab_stacks->a;
	a_arr = a->content;
	b = ab_stacks->b;
	b_arr = b->content;
	number_to_top(a, smallest(a));
	if (get_index(smallest(a), a) == a->head)
		push_stack(a, b);
	if (b_arr[b->head] < b_arr[b->tail])
		rotate_stack(b);
	if (a_arr[a->tail] < a_arr[a->head])
		rotate_stack(a);
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}