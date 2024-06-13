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
	while (i < ab->a->entries)
	{
		if (ab->a->content[ab->a->head] <= mean)
			push_stack(ab->a, ab->b);
		else
			rotate_stack(ab->a);
		i++;
	}
	number_to_top(ab->a, smallest(ab->a));
	number_to_top(ab->b, biggest(ab->b));
}

static int	best_fit(t_stack *src, t_stack *dst) //best number from src to push to closest
{
	int	best_cost;
	int	cost;
	int	best_ref;
	int	tar;
	int	i;

	i = 0;
	best_cost = INT_MAX;
	best_ref = 0;
	while (i++ < src->entries)
	{
		if (src->id == 'a')
			tar = closest_down(dst, src->content[src->head + i]);
		else
			tar = closest_up(dst, src->content[src->head + i]);
		cost = push_target_cost(src->content[src->head + i], tar, src, dst);
		if (cost < best_cost)
		{
			best_ref = src->content[src->head + i];
			best_cost = cost;
		}
	}
	return (best_ref);
}


static void	push_best_fit(t_stacks *ab)
{

	int	best;

	if (get_index(smallest(ab->a), ab->a) == ab->a->head)
		rotate_stack(ab->a);
	best = best_fit(ab->a, ab->b);
	number_to_top(ab->b, closest_down(ab->b, best));
	push_number(ab->a, ab->b, best);
	return ;
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
	push_best_fit(ab);
	if (a->entries == 1 || !sorted_asc(b, b->head, b->tail))
		repeat_push(b->entries, b, a);
}