/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instuctions_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:42 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/31 12:14:09 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    push_stack(t_stack *src, t_stack *dst)
{
	int	temp;

	if (is_full(dst) || is_empty(src))
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
}