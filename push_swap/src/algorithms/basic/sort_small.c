/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:15:08 by ravargas          #+#    #+#             */
/*   Updated: 2024/07/03 13:27:01 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	sort_five(t_stacks *ab)
{
	t_stack	*a;
	t_stack	*b;

	a = ab->a;
	b = ab->b;
	if (sorted_asc(a, a->head, a->tail))
		return ;
	if (a->moves == 0 && b->entries == 0)
	{
		push_number(a, b, smallest(a));
		push_number(a, b, smallest(a));
	}
	if (a->entries == 3 && sorted_desc(a, a->head, a->tail))
		sort_three(ab);
	push_back(b, a);
}

void	mini_sort(t_stack *s)
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

static int	cases(t_stack *a)
{
	int	small;
	int	big;
	int	i_small;
	int	j_big;

	big = biggest(a);
	small = smallest(a);
	i_small = get_index(small, a);
	j_big = get_index(big, a);
	if (i_small == 1 && j_big == 2)
		return (1);
	if (i_small == 2 && j_big == 0)
		return (2);
	if (i_small == 0 && j_big == 1)
		return (3);
	if (i_small == 1 && j_big == 0)
		return (4);
	return (0);
}

void	sort_three(t_stacks *ab)
{
	t_stack	*s;

	s = ab->a;
	if (!sorted_asc(s, s->head, s->tail))
	{
		if (cases(s) == 1)
			swap_stack(s);
		if (cases(s) == 2)
			number_to_top(s, smallest(s));
		if (cases(s) == 3)
		{
			swap_stack(s);
			rotate_stack(s);
		}
		if (cases(s) == 4)
			number_to_top(s, smallest(s));
		else
			number_to_top(s, smallest(s));
	}
	return ;
}
