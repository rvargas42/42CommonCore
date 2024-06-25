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


static void	push_two(t_stack *src, t_stack *dst)
{
	int	min;
	int	max;
	int	n;

	max = biggest(src);
	min = smallest(src);
	//ft_printf("smallest: %d | biggest %d\n", min, max);
	while (dst->entries != 2)
	{
		n = src->content[src->head];
		if (n == max || n == min)
			rotate_stack(src);
		else
			push_stack(src, dst);
	}
}

static void	push_opt_b(t_stack *src, t_stack *dst)
{
	int	best;
	int	closest;
	int	index;

	best = optimum_insert_a(src, dst);
	closest = closest_up(dst, best, dst->head, dst->tail);
	index = get_index(closest, dst);
	if (best >= (biggest(src)) && best >= biggest(dst))
	{
		reverse_rotate(src);
		return ;
	}
	if (best > closest)
	{
		number_to_top(dst, biggest(dst));
		push_number(src, dst, best);
	}
	else
		insert_number(src, dst, best, index + 1);
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

static void	push_back(t_stack *src, t_stack *dst)
{
	int	close;
	int	index;
	int	n;
	
	mini_sort(dst);
	while (dst->entries < dst->max_size)
	{
		n = src->content[src->head];
		close = closest_up(dst, src->content[src->head], dst->head, dst->tail);
		index = get_index(close, dst);
		if (n < close)
		{
			number_to_top(dst, close);
			push_stack(src, dst);
		}
		else
			insert_number(src, dst, n, index + 1);
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
		push_two(a, b);
	else
		push_opt_b(a, b);
	if (a->entries == 3) //TODO: Funcion que inserta a a los mas optimos de vuelta cuando a->entries == 3
	{
		number_to_top(b, biggest(b));
		//print_stacks(ab);
		push_back(b, a);
		//ft_printf("a_moves: %d\n", a->moves);
		//ft_printf("b_moves: %d\n", b->moves);
		exit(EXIT_FAILURE);
		//number_to_top(a, smallest(a));
	}
}