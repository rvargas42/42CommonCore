/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:15:15 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/08 16:52:25 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_rvr(t_stack *s)
{
	write(1, "rr", 2);
	write(1, &s->id, 1);
	write(1, "\n", 1);
}

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
	s->moves++;
	print_rvr(s);
}

void	repeat_rvrotate(int n, t_stack *s)
{
	int	i;
	
	if (n <= 0 || !s)
		return ;
	i = 0;
	while (i != n)
	{
		reverse_rotate(s);
		i++;
	}
}