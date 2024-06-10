/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:15:00 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/10 16:19:37 by ravargas         ###   ########.fr       */
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
	int	*arr;
	int	closest;
	int	value;
	
	i = 0;
	arr = s->content;
	closest = arr[0];
	ft_printf("ref : %d\n", ref);
	while ((value = arr[i]))
	{
		if ((value > ref || closest == -1) && (closest == -1 || abs(value - ref) < abs(closest - ref)))
            closest = value;
        i++;
		if (value - ref == 1)
			return value;
		i++;
	}
	return (closest);
}

int	closest_down(t_stack *s, int ref)
{
	int	i;
	int	*arr;
	int	closest;
	int	value;
	
	i = 0;
	arr = s->content;
	closest = arr[0];
	ft_printf("ref : %d\n", ref);
	while ((value = arr[i]))
	{
		if (value != ref)
		{
			if (abs(ref - value) < abs(ref - closest) && value < ref)
				closest = arr[i];
		}
		i++;
	}
	return (closest);
}