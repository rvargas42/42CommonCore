/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:07:55 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/30 18:00:07 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	test_instructions(t_stacks *stacks)
{
	int	i;

	i = 12;
	while (i != 0)
	{
		ft_printf("a_entries: %d, a_head: %d, a_tail: %d\n", stacks->a->entries, stacks->a->head, stacks->a->tail);
		ft_printf("b_entries: %d, b_head: %d, b_tail: %d\n", stacks->b->entries, stacks->b->head, stacks->b->tail);
		//push_stack(stacks->a, stacks->b);
		print_buffer(stacks->a);
		ft_printf("\n");
		print_buffer(stacks->b);
		ft_printf("\n");
		reverse_rotate(stacks->a);
		//ft_printf("a_entries: %d\n", stacks->a->entries);
		i--;
	}
}