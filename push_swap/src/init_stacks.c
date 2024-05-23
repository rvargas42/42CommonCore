/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:06:09 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 14:09:33 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//TODO: check structures and test
static void	init_buffer_a(t_stack *a, int *unordered, int max_size)
{
	a->buffer->content = unordered;
	a->buffer->head = &(unordered[0]);
	a->buffer->tail = &(unordered[max_size - 1]);
	a->buffer->max_size = max_size;
}
static void init_buffer_b(t_stack *b, int max_size)
{
	int	*empty_array;

	empty_array = ft_calloc(max_size, sizeof(int));
	b->buffer->content = empty_array;
	b->buffer->head = &(empty_array[0]);
	b->buffer->tail = &(empty_array[max_size - 1]);
	b->buffer->max_size = max_size;
}

t_stacks	init_stacks(int *unordered, int max_size)
{
	t_stacks	ab_stacks;
	t_stack		b;
	t_stack		a;
	
	init_buffer_a(&a, unordered, max_size);
	init_buffer_b(&b, max_size);
	ab_stacks.a = a;
	ab_stacks.b = b;

	return (ab_stacks);
}