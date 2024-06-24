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

	i = 1;
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
		}
		i++;
	}
	return (best);
}

static void	push_opt_b(t_stack *src, t_stack *dst)
{
	int	best;
	int	closest;
	int	index;

	best = optimum_insert(src, dst);
	closest = closest_down(dst, best, dst->head, dst->tail);
	index = get_index(closest, dst);
	insert_number(src, dst, best, index);
}

static void	push_back(t_stack *src, t_stack *dst)
{
	int	closest;
	
	if (dst->entries == 0)
		push_stack(src, dst);
	while (dst->entries < dst->max_size)
	{
		closest = closest_down(src, dst->content[dst->head], src->head, src->tail);
		if (closest == src->content[src->head])
			push_stack(src, dst);
		else
			number_to_top(src, closest);
	}
}

static void mini_sort(t_stack *s)
{
	if (!sorted_asc(s, s->head, s->tail))
	{
		number_to_top(s, smallest(s));
		if (s->content[s->head + 1] > s->content[s->tail])
		{
			number_to_top(s, biggest(s));
			swap_stack(s);
			reverse_rotate(s);
		}
		if (s->content[s->head] > s->content[s->head + 1])
			swap_stack(s);
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
	if (b->entries == 0)
		repeat_push(2, a, b);
	else
		push_opt_b(a, b);
	if (a->entries == 0)
	{
		//print_stacks(ab);
		number_to_top(b, biggest(b));
		push_back(b, a);
		//print_stacks(ab);
	}
	if (a->entries == 0)
		repeat_push(b->entries, b, a);
		number_to_top(a, smallest(a));
	return ;
}