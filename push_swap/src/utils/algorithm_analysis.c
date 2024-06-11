/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:31:50 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 13:38:04 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	push_cost(int index, t_stack *s)
{
	int	cost;
	int	midpoint;

	midpoint = s->head + ((s->entries) / 2);
	if (index > midpoint)
		return (s->tail - index + 1);
	if (s->entries == 0 || index < s->head)
		return (0);
	else
		return (index - s->head);
}

int	push_target_cost(int ref_index, int target_index, t_stacks *ab)
{
	return (1);
}

int	optimum_cost_min(t_stack *s, int ref)
{
	int	i;
	int	*arr;
	int	closest;
	int	value;
	int	cost;
	
	i = 0;
	arr = s->content;
	closest = INT_MIN;
	cost = push_cost(smallest(s), s);
	ft_printf("ref : %d\n", ref);
	while ((value = arr[s->head + i]))
	{
		if (value < ref && value > closest)
			closest = value;
		if (push_cost(value, s) < cost && value < ref)
			return (value);
		i++;
	}
	return (closest);
}