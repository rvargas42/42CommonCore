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

static int	optimum_insert(t_stack *src, t_stack *dst)
{
	int	i;
	int	best;
	int	closest;
	int	distance;
	int	current;

	i = 0;
	best = src->content[src->head];
	distance = INT_MAX;
	while (src->head + i < src->tail)
	{
		current = src->content[src->head + i];
		closest = closest_down(dst, current, dst->head, dst->tail);
		if ((push_distance(current, closest, src, dst)) < distance)
		{
			distance = push_distance(current, closest, src, dst);
			best = current;
			ft_printf("current = %d | closest_Down: %d | distance = %d\n", current, closest, distance);
		}
		i++;
	}
	ft_printf("best = %d\n", best);
	return (best);
}

static void	insert_best(t_stacks *ab, t_stack *src, t_stack *dst)
{
	int	best;
	int index;

	best = optimum_insert(src, dst);
	index = get_index((closest_down(src, best, dst->head, dst->tail)), dst);
	if (get_index(best, src) == index - 1)
		repeat_rotate(2, src);
	insert_number(src, dst, best, index);
	repeat_rotate(2, src);
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
	insert_best(ab_stacks, a, a);
	print_stacks(ab_stacks);
	if (a->entries == 1)
		repeat_push(b->entries, b, a);
}