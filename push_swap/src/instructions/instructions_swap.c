/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:11 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/31 12:08:26 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    swap_stack(t_stack *s)
{
    int temp;

    if (is_empty(s) || s->entries < 2)
        return ;
	else
	{
		temp = s->content[s->head];
		s->content[s->head] = s->content[s->head + 1];
		s->content[s->head + 1] = temp;
	}
}