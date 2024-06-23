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
			//ft_printf("current = %d | closest_Down: %d | distance = %d\n", current, closest, distance);
		}
		i++;
	}
	return (best);
}

static void	push_optimum(t_stack *src, t_stack *dst)
{
	int	best;
	int	index;

	best = optimum_insert(src, dst);
	index = get_index(closest_up(dst, best, dst->head, dst->tail), dst);
	insert_number(src, dst, best, index);
}

static void	mean_sep(t_stacks *ab, int n)
{
	int	mean;
	int	i;

	i = 0;	
	mean = stack_mean(ab->a);
	while (i++ < n)
	{
		if (ab->a->content[ab->a->head + i] <= mean)
			push_stack(ab->a, ab->b);
	}
}


void	insertion_sort(t_stacks *ab)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;

	a = ab->a;
	a_arr = a->content;
	b = ab->b;
	b_arr = b->content;
	if (b->moves == 0)
		repeat_push(2, a, b);
	else
		push_optimum(a, b);
	if (a->entries == 0)
		repeat_push(b->entries, b, a);
		number_to_top(a, smallest(a));
	//print_stacks(ab);
	return ;
}