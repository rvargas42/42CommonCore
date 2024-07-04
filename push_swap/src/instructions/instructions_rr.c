/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:09:57 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/28 12:12:42 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_rr(void)
{
	write(1, "rr\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate_stack(stacks->a);
	rotate_stack(stacks->b);
	print_rr();
}

void	repeat_rr(int n, t_stacks *ab_stacks)
{
	int	i;

	if (n <= 0 || !ab_stacks)
		return ;
	i = 0;
	while (i != n)
	{
		rr(ab_stacks);
		i++;
	}
}
