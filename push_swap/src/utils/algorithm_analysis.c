/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:31:50 by ravargas          #+#    #+#             */
/*   Updated: 2024/07/02 10:56:40 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	push_cost(int index, t_stack *s)
{
	int	midpoint;

	midpoint = s->head + ((s->entries) / 2);
	if (index > midpoint)
		return (s->tail - index + 1);
	if (s->entries == 0 || index < s->head)
		return (0);
	else
		return (index - s->head);
}

int	push_target_cost(int ref, int target, t_stack *src, t_stack *dst)
{
	int	ref_index;
	int	tar_index;

	ref_index = get_index(ref, src);
	tar_index = get_index(target, src);
	if (ref_index < src->head && tar_index < src->head)
		return (push_cost(ref, dst) + push_cost(target, dst));
	if (ref_index < src->head && tar_index >= src->head)
		return (push_cost(ref, dst) + push_cost(target, src));
	if (ref_index >= src->head && tar_index >= src->head)
		return (push_cost(ref, src) + push_cost(target, src));
	if (ref_index >= src->head && tar_index < src->head)
		return (push_cost(ref, src) + push_cost(target, dst));
	return (0);
}
