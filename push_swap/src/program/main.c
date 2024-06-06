/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:24 by ravargas         ###   ########.fr       */
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
	while (keep_running(ab_stacks->a))
	{
		bubble_sort(ab_stacks);
		return ;
	}
}

int main(int argn, char const **argv)
{
	int			*unordered;
	t_stacks	*ab_stacks;

	if (argn < 2)
		exit(EXIT_SUCCESS);
	unordered = unordered_nums(argn, argv);
	ab_stacks = init_stacks(&unordered, array_len(unordered));
	execute_sorting(ab_stacks);
	test_instructions(ab_stacks);
	//push_swap(st_stacks)
	free_all(ab_stacks); //TODO: function that frees all data
	return (1);
}