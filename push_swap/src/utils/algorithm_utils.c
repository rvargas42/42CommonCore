/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:40:48 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/07 09:28:46 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	smallest_to_top(t_stack *s)
{
	int	*arr;
	int	small_index;
	int	cost;
	int	midpoint;

	arr = s->content;
	small_index = get_index(smallest(s), s);
	cost = push_cost(small_index, s);
	ft_printf("cost_to_push: %d\n", cost);
	midpoint = s->head + ((s->entries) / 2);
	if (small_index == s->head)
		return ;
	if (small_index < midpoint)
	{
		repeat_rotate(cost, s);
		return ;
	}
	if (small_index >= midpoint)
	{
		repeat_rvrotate(cost, s);
		return ;
	}
}

int	get_index(int n, t_stack *s)
{
	int	i;
	int	num;
	int	*arr;

	i = 0;
	arr = s->content;
	while ((num = arr[s->head + i]) != NULL)
	{
		if (num == n)
			return (s->head + i);			
		i++;
	}
	return (s->head);
}
