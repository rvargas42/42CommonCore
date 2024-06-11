/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:40:48 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 13:38:54 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	index_to_top(t_stack *s, int number)
{
	int	*arr;
	int	index;
	int	midpoint;
	int	cost;

	index = get_index(number, s);
	arr = s->content;
	cost = push_cost(index, s);
	midpoint = s->head + ((s->entries) / 2);
	if (index == 1)
	{
		swap_stack(s);
		return ;
	}
	if (index <= midpoint)
	{
		repeat_rotate(cost, s);
		return ;
	}
	if (index > midpoint)
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
	while ((num = arr[s->head + i]))
	{
		if (num == n)
			return (s->head + i);			
		i++;
	}
	return (s->head);
}
