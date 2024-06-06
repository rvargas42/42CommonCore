/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:16:51 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 18:55:47 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ss(t_stacks *stacks)
{
    swap_stack(stacks->a);
	swap_stack(stacks->b);
}

void	repeat_ss(int n)
{
	return ;
}