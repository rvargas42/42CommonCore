/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:15:00 by ravargas          #+#    #+#             */
/*   Updated: 2024/07/03 11:50:53 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	absol(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * -1);
}

int	closest_up(t_stack *s, int ref, int start, int end)
{
	int	i;
	int	closest;
	int	value;

	i = 0;
	closest = INT_MAX;
	while (start + i <= end)
	{
		value = s->content[start + i];
		if (value > ref && value < closest)
			closest = value;
		i++;
	}
	if (closest == INT_MAX)
		closest = biggest(s);
	return (closest);
}

int	closest_down(t_stack *s, int ref, int start, int end)
{
	int	i;
	int	closest;
	int	value;

	i = 0;
	closest = INT_MIN;
	while (start + i <= end)
	{
		value = s->content[start + i];
		if (value < ref && value > closest)
			closest = value;
		i++;
	}
	if (closest == INT_MIN)
		closest = smallest(s);
	return (closest);
}

int	biggest(t_stack *s)
{
	int	i;
	int	comp;
	int	temp;

	i = 1;
	temp = s->content[s->head];
	while (s->head + i <= s->tail)
	{
		comp = s->content[s->head + i];
		if (temp < comp)
			temp = comp;
		i++;
	}
	return (temp);
}

int	smallest(t_stack *s)
{
	int	i;
	int	comp;
	int	temp;

	i = 1;
	temp = s->content[s->head];
	while (s->head + i <= s->tail)
	{
		comp = s->content[s->head + i];
		if (temp > comp)
			temp = comp;
		i++;
	}
	return (temp);
}
