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

static int	optimum_insert_b(t_stack *src, t_stack *dst)
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

static int	optimum_insert_a(t_stack *src, t_stack *dst)
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
		closest = closest_up(dst, current, dst->head, dst->tail);
		if ((push_distance(current, closest, src, dst)) < distance)
		{
			distance = push_distance(current, closest, src, dst);
			best = current;
		}
		i++;
	}
	return (best);
}

static void	push_opt_a(t_stack *src, t_stack *dst)
{
	int	best;
	int	closest;
	int	index;

	best = optimum_insert_a(src, dst);
	closest = closest_up(dst, best, dst->head, dst->tail);
	index = get_index(closest, dst);
	if (best > closest)
	{
		number_to_top(dst, biggest(dst));
		push_number(src, dst, best);
	}
	else
		insert_number(src, dst, best, index + 1);
}

static void	push_opt_b(t_stack *src, t_stack *dst)
{
	int	best;
	int	closest;
	int	index;

	best = optimum_insert_a(src, dst);
	closest = closest_up(dst, best, dst->head, dst->tail);
	index = get_index(closest, dst);
	if (best > closest)
	{
		number_to_top(dst, biggest(dst));
		push_number(src, dst, best);
	}
	else
		insert_number(src, dst, best, index + 1);
}

static void	push_back(t_stack *src, t_stack *dst)
{
	int	closest;

	if (dst->entries == 0)
		push_number(src, dst, biggest(src));
	while (dst->entries < dst->max_size)
	{
		closest = closest_down(src, dst->content[dst->head], src->head, src->tail);
		if (src->content[src->head] == closest)
			push_number(src, dst, src->content[src->head]);
		else
			reverse_rotate(src);
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
	if (a->entries == 0) //TODO: Funcion que inserta a a los mas optimos de vuelta cuando a->entries == 3
	{
		number_to_top(b, biggest(b));
		//ft_printf("a_moves: %d\n", a->moves);
		//ft_printf("b_moves: %d\n", b->moves);
		//print_stacks(ab);
		push_back(b, a);
		//exit(EXIT_FAILURE);
		//number_to_top(a, smallest(a));
	}
}