/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:31 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/12 16:51:12 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_rotate(t_stack *s)
{
	write(1, "r", 1);
	write(1, &s->id, 1);
	write(1, "\n", 1);
}

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
	s->moves++;
	print_rotate(s);
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