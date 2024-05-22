/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:06:09 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/22 13:40:48 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

d_llist	**build_dllist(int n_nodes) // TODO: Terminar esta funcion y poblar lista enlazada 
{
	
}
 
void	init_stack(ps_stack *stack, int *unordered) // TODO: revisar
{
	int		i;
	d_llist	**dllist;

	i = 0;
	dllist = build_dllist(*unordered);
	stack->top = dllist;
	
}

stacks	init_stacks(int *unordered) //TODO: revisar
{
	stacks		st_stacks;
	ps_stack	*a;
	ps_stack	*b;

	a = malloc(sizeof(ps_stack));
	b = malloc(sizeof(ps_stack));

	init_stack(a, unordered);
	init_stack(b, NULL);
	
	st_stacks.a = a;
	st_stacks.b = b;
	
	return (st_stacks);
}