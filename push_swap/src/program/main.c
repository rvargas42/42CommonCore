/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/27 12:35:09 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	keep_running(t_stack *s)
{
	int	i;

	i = 0;
	if (is_full(s))
	{
		while (s->content[i + 1])
		{
			if (s->content[i] > s->content[i + 1])
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

static void	execute_sorting(t_stacks *ab_stacks)
{
	int	i;

	i = 0;
	while (keep_running(ab_stacks->a))
	{
		if (ab_stacks->a->max_size < 3)
			swap_stack(ab_stacks->a);
		if (ab_stacks->a->max_size == 3)
			sort_three(ab_stacks);
		if (ab_stacks->a->max_size <= 5)
			sort_five(ab_stacks);
		if (ab_stacks->a->max_size > 5)
			insertion_sort(ab_stacks);
		i++;
	}
}

int main(int argn, char const **argv)
{
	int			*unordered;
	t_stacks	*ab_stacks;

	if (argn < 2)
		return (-1);
	unordered = unordered_nums(argn, argv);
	if (! unordered)
		exit(EXIT_FAILURE);
	ab_stacks = init_stacks(&unordered, array_len(unordered));
	if (!ab_stacks)
		exit(EXIT_FAILURE);
	execute_sorting(ab_stacks);
	free_all(ab_stacks);
	return (1);
}