/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:11 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/28 12:14:47 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_swap(t_stack *s)
{
	write(1, "s", 1);
	write(1, &s->id, 1);
	write(1, "\n", 1);
}

void	swap_stack(t_stack *s)
{
	int	temp;

	if (is_empty(s) || s->entries < 2)
		return ;
	else
	{
		temp = s->content[s->head];
		s->content[s->head] = s->content[s->head + 1];
		s->content[s->head + 1] = temp;
	}
	s->moves++;
	print_swap(s);
}

void	repeat_swap(int n, t_stack *s)
{
	int	i;

	if (n <= 0 || !s)
		return ;
	i = 0;
	while (i != n)
	{
		swap_stack(s);
		i++;
	}
}
