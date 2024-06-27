/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:15:08 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/27 11:57:30 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	sort_five(t_stacks *ab)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_arr;
	int		*b_arr;

	a = ab->a;
	a_arr = a->content;
	b = ab->b;
	b_arr = b->content;
	if (a->moves == 0 && b->entries == 0)
	{
		push_number(a, b, smallest(a));
		push_number(a, b, smallest(a));
	}
	//print_stacks(ab);
	if (a->entries == 3 && sorted_desc(a, a->head, a->tail))
		sort_three(ab);
	push_back(b, a);
}

void mini_sort(t_stack *s)
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

void	sort_three(t_stacks *ab)
{
	t_stack	*s;
	int		small;
	int		big;

	s = ab->a;
	small = smallest(s);
	big = biggest(s);
	if (!sorted_asc(s, s->head, s->tail))
	{
		if (s->content[s->head] > s->content[s->head + 1])
			swap_stack(s);
		if (get_index(small, s) == s->head + 1)
		{
			reverse_rotate(s);
			return ;
		}
		if (get_index(small, s) == 0 && get_index(big, s) == 1)
		{
			rotate_stack(s);
			swap_stack(s);
			return ;
		}
		number_to_top(s, small);
	}
}

