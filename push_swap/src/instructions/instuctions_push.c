/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instuctions_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:42 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/28 12:15:23 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_push(t_stack *dst)
{
	write(1, "p", 1);
	write(1, &(dst->id), 1);
	write(1, "\n", 1);
}

void	push_stack(t_stack *src, t_stack *dst)
{
	int	temp;

	if (is_full(dst) || is_empty(src) || src == dst)
		return ;
	else
	{
		temp = src->content[src->head];
		dst->entries++;
		dst->head = (dst->max_size - dst->entries);
		dst->content[dst->head] = temp;
		src->entries--;
		if (src->entries == 0)
			src->head = src->tail;
		else
			src->head = (src->max_size - src->entries);
	}
	src->moves++;
	print_push(dst);
}

void	repeat_push(int n, t_stack *src, t_stack *dst)
{
	int	i;

	if (n <= 0 || !src || !dst)
		return ;
	i = 0;
	while (i != n)
	{
		push_stack(src, dst);
		i++;
	}
}
