/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:25:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/13 20:05:35 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void mean_sep(t_stacks *ab) //pushes to b numbers bellow mean
{
	int	mean;
	int	i;
	
	i = 0;
	mean = stack_mean(ab->a);
	ft_printf("mean : %d\n", mean);
	while (i < ab->a->max_size)
	{
		if (ab->a->content[ab->a->head] < mean)
			push_stack(ab->a, ab->b);
		else
			rotate_stack(ab->a);
		i++;
	}
	number_to_top(ab->a, smallest(ab->a));
	number_to_top(ab->b, biggest(ab->b));
}

static void insert_number(t_stack *src, t_stack *dst, int ref, int pos)
{
	if (get_index(ref, src) == 0 && pos == 1)
		swap_stack(src);
	else
	{
		push_number(src, dst, ref);
		number_to_top(src, src->content[pos]);
		push_number(dst, src, ref);
	}
}


static void sort_stack_a(t_stacks *ab, t_stack *s)
{
	int	closest;
	int	ref;
	int	n;

	n = s->entries;
	if (sorted_desc(s, s->head, s->tail))
		return ;
	ref = s->content[s->head];
	closest = closest_up(s, ref);
	if (closest == INT_MAX)
		closest = biggest(s);
	ft_printf("ref = %d | closest_up: %d\n", ref, closest);
	if (ref != closest && get_index(closest, s) != 1 && get_index(ref, s) != 0)
		insert_number(s, ab->b, get_index(closest, s), s->head + 1);
	reverse_rotate(s);
}


static void sort_stack_b(t_stacks *ab, t_stack *s)
{
	int	closest;
	int	ref;
	int	n;

	n = s->entries;
	if (sorted_desc(s, s->head, s->tail))
		return ;
	ref = s->content[s->head];
	closest = closest_down(s, ref);
	if (closest == INT_MIN)
		closest = smallest(s);
	ft_printf("ref = %d | closest_down: %d\n", ref, closest);
	if (ref != closest)
		insert_number(s, ab->a, get_index(closest, s), s->head + 1);
	reverse_rotate(s);
	print_stacks(ab);
}

void	insertion_sort_opt(t_stacks *ab)
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
		mean_sep(ab);
	
	while (!sorted_desc(b, b->head, b->tail))
		sort_stack_a(ab, ab->a);
	sort_stack_b(ab, ab->b);
	if (a->entries == 1 || sorted_desc(b, b->head, b->tail))
		repeat_push(b->entries, b, a);
}