/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:44:56 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 15:53:50 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	keep_running(t_stack *s)
{
	int	i;

	i = 0;
	if (is_full(s))
	{
		while (s->content[i + 1])
		{
			if (s->content[i] > s->content[i + 1])
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_full(t_stack *s)
{
	if (s->entries == s->max_size)
		return (1);
	else
		return (0);
}

int	is_empty(t_stack *s)
{
	if (s->head == s->tail && s->entries == 0)
		return (1);
	else
		return (0);
}