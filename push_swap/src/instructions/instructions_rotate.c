/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 19:06:02 by ravargas         ###   ########.fr       */
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

void	repeat_rotate(int n, t_stack *s)
{
	int	i;
	
	if (n <= 0 || !s)
		return ;
	i = 0;
	while (i != n)
	{
		rotate_stack(s);
		i++;
	}
}