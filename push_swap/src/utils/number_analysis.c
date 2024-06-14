/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:15:00 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/11 12:46:04 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * -1);
}

int	closest_up(t_stack *s, int ref)
{
	int	i;
	int	closest;
	int	value;
	
	i = 0;
	closest = INT_MAX;
	while ((value = s->content[s->head + i]))
	{
		if (value > ref && value < closest)
			closest = value;
		i++;
	}
	return (closest);
}

int	closest_down(t_stack *s, int ref)
{
	int	i;
	int	closest;
	int	value;
	
	i = 0;
	closest = INT_MIN;
	while ((value = s->content[s->head + i]))
	{
		if (value < ref && value > closest)
			closest = value;
		i++;
	}
	return (closest);
}

int	biggest(t_stack *s)
{
	int	i;
	int	comp;
	int	temp;

	i = 1;
	temp = s->content[s->head];
	while ((comp = s->content[s->head + i]))
	{
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
	while ((comp = s->content[s->head + i]))
	{
		if (temp > comp)
			temp = comp;
		i++;
	}
	return (temp);
}