/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:45:33 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/13 19:46:02 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	sorted_asc(t_stack *s, int start, int finish)
{
	int	i;
	int	comp;
	int	value;

	i = 0;
	comp = s->content[start];
	while (i < finish)
	{
		value = s->content[start + i];
		if (value < comp)
			return (0);
		else
			comp = value;
		i++;
	}
	return (1);
}

int	sorted_desc(t_stack *s, int start, int finish)
{
	int	i;
	int	comp;
	int	value;

	i = 0;
	comp = s->content[start];
	while (i < finish)
	{
		value = s->content[start + i];
		if (value > comp)
			return (0);
		else
			comp = value;
		i++;
	}
	return (1);
}