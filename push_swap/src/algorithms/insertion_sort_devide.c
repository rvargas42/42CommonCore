/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_devide.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:25:27 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 14:36:05 by ravargas         ###   ########.fr       */
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
	ft_printf("range: %d\n", range);
	while (range-- > 0)
		push_stack(src, dst);
}

void	insertion_sort_divide(t_stacks *ab)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;

	a = ab->a;
	a_arr = a->content;
	b = ab->b;
	b_arr = b->content;
	while (get_index(smallest(a), a) != a->head)
	{
		if (b->entries < 1 || a_arr[a->head] > b_arr[b->head])
			push_stack(a, b);
		if (a_arr[a->head] > a_arr[a->head + 1])
		{
			swap_stack(a);
			rotate_stack(a);
		}
		push_range(a, b);
	}
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}