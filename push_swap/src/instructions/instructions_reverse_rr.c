/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:16:05 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 19:07:03 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}

void	repeat_rvrr(int n, t_stacks *ab_stacks)
{
	int	i;
	
	if (n <= 0 || !ab_stacks)
		return ;
	i = 0;
	while (i != n)
	{
		rrr(ab_stacks);
		i++;
	}
}