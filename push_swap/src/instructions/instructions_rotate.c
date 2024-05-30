/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/30 17:39:53 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    rotate_stack(t_stack *s)
{
	int	i;
	int	h;

	if (s->entries < 2)
		return ;	
	i = 0;
	h = s->content[s->head];
	while (i < s->entries -  1)
	{
		s->content[s->head + i] = s->content[s->head + i + 1];
		i++;
	}
	s->content[s->head + i] = h;
}