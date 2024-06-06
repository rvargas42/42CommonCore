/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:25:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 18:50:37 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	bubble_sort(t_stacks *ab_stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = ab_stacks->a;
	b = ab_stacks->b;
	if (b->entries < 2)
		repeat_instruct(2, INSTRUCT_PUSH);
	if (a->content[a->head])
}