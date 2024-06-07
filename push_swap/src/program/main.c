/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/07 09:29:49 by ravargas         ###   ########.fr       */
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
		//print_stacks(ab_stacks); //TODO: borrar prints
		//ft_printf("tail: %d | head: %d\n", ab_stacks->a->tail, ab_stacks->a->head);
		//ft_printf("midpoint: %d\n", mid_point(ab_stacks->a->head, ab_stacks->a->tail,ab_stacks->a->entries));
		//ft_printf("a mid_point: %d\n", ab_stacks->a->content[mid_point(ab_stacks->a->head, ab_stacks->a->tail,ab_stacks->a->entries)]);
		//ft_printf("push_cost: %d\n", push_cost(mid_point(ab_stacks->a->head, ab_stacks->a->tail, ab_stacks->a->entries),ab_stacks->a));
		bubble_sort(ab_stacks);
		i++;
	}
	//ft_printf("-> Instructions done: %d\n",i); //TODO: borrar
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
	//ft_printf("midpoint: %d\n", mid_point(ab_stacks->a->head, ab_stacks->a->tail,ab_stacks->a->entries));
	free_all(ab_stacks);
	return (1);
}