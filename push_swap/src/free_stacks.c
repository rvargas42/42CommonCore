/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:04:55 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 14:05:39 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *s)
{
	if (s)
	{
		if (s->content)
			free(s->content);
		free(s);
	}
	else
		return ;
}

void	free_all(t_stacks *ab_stacks) //TODO: terminar
{
	if (ab_stacks)
	{
		free_stack(ab_stacks->a);
		free_stack(ab_stacks->b);
		free(ab_stacks);
	}
}