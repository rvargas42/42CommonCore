/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:11 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/28 17:30:05 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    swap_stack(t_stack *s)
{
    int temp;

    if (array_len(s->content) <= 1 || !s)
        return ;
    temp = s->content[1];
    s->content[0] = temp;
    
    return ;
}