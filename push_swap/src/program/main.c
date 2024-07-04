/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/07/04 12:39:49 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	keep_running(t_stack *s)
{
	int	i;

	i = 0;
	if (sorted_asc(s, s->head, s->tail))
		return (0);
	if (is_full(s))
	{
		while (i != s->max_size)
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

static int	get_stack_size(char const **args, int argn)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (argn > 2)
		return (argn - 1);
	if (argn == 2)
	{
		while (args[1][i])
		{
			if (args[1][i] == ' ')
				++len;
			i++;
		}
	}
	return (len + 1);
}

int	main(int argn, char const **argv)
{
	int			*unordered;
	t_stacks	*ab_stacks;
	int			stack_size;

	stack_size = get_stack_size(argv, argn);
	if (argn < 2)
		return (-1);
	unordered = unordered_nums(argn, argv, stack_size);
	if (!unordered)
		exit(EXIT_FAILURE);
	ab_stacks = init_stacks(&unordered, stack_size);
	if (!ab_stacks)
		exit(EXIT_FAILURE);
	execute_sorting(ab_stacks);
	free_all(ab_stacks);
	return (1);
}
