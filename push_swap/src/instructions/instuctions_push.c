/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instuctions_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:42 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/30 12:00:24 by ravargas         ###   ########.fr       */
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
		src->entries--;
		dst->entries++;
		src->head++;
		dst->head--;
		dst->content[dst->head] = temp;
	}
}