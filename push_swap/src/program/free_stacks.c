/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:04:55 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/26 12:33:07 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_stack(t_stack *s)
{
	if (s->content)
		free(s->content);
	free(s);
}

void	free_all(t_stacks *ab_stacks)
{
    if (ab_stacks) {
        if (ab_stacks->a) {
            free(ab_stacks->a->content);
            free(ab_stacks->a);
        }
        if (ab_stacks->b) {
            free(ab_stacks->b->content);
            free(ab_stacks->b);
        }
        free(ab_stacks);
    }
}