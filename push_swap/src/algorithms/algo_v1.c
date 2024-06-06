/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:45:10 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/31 15:55:54 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	only_push(t_stacks *stacks)
{
	int	a;
	int	b;

	a = stacks->a->content[stacks->a->head];
	b = stacks->b->content[stacks->b->head];
	if (is_empty(stacks->b) || a < b)
		push_stack(stacks->a, stacks->b);
}