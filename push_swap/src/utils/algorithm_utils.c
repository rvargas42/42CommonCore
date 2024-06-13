/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:40:48 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/13 19:48:34 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	number_to_top(t_stack *s, int number)
{
	int	*arr;
	int	index;
	int	midpoint;
	int	cost;

	index = get_index(number, s);
	arr = s->content;
	cost = push_cost(index, s);
	midpoint = s->head + ((s->entries) / 2);
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

void	push_number(t_stack *src, t_stack *dst, int n)
{
	number_to_top(src, n);
	push_stack(src, dst);	
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

void insert_number(t_stack *s, int ref, int pos)
{
	return ;
}

int	is_in_a(t_stack *s, int num)
{
	if (get_index(num, s) < s->head)
		return (0);
	else
		return (1);
}
