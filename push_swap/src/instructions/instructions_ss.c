/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:16:51 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/28 12:13:40 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_ss(void)
{
	write(1, "ss\n", 3);
}

void	ss(t_stacks *stacks)
{
	swap_stack(stacks->a);
	swap_stack(stacks->b);
	print_ss();
}

void	repeat_ss(int n, t_stacks *ab_stacks)
{
	int	i;

	if (n <= 0 || !ab_stacks)
		return ;
	i = 0;
	while (i != n)
	{
		ss(ab_stacks);
		i++;
	}
}
