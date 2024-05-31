/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:15:15 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/31 12:29:37 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    reverse_rotate(t_stack *s)
{
	int	t;
	int	i;

	if (s->entries < 2 || is_empty(s))
		return ;
	t = s->content[s->tail];
	i = 0;
	while (i < s->entries - 1)
	{
		s->content[s->tail - i] = s->content[s->tail - i - 1];
		i++;
	}
	s->content[s->head] = t;
    return ;
}