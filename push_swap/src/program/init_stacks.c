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

#include "../../inc/push_swap.h"

static void	*init_buffer_a(int **unordered, int max_size)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	a->content = *unordered;
	a->id = 'a';
	a->head = 0;
	a->tail = max_size;
	a->entries = max_size;
	a->max_size = max_size;
	return (a);
}

static void *init_buffer_b(int max_size)
{
	int		*empty_array;
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	empty_array = ft_calloc(max_size, sizeof(int *));
	b->content = empty_array;
	b->id = 'b';
	b->head = max_size;
	b->tail = max_size;
	b->entries = 0;
	b->max_size = max_size;
	return (b);
}

t_stacks	*init_stacks(int **unordered, int max_size)
{
	t_stacks	*ab_stacks;
	t_stack		*b;
	t_stack		*a;
	
	ab_stacks = malloc(sizeof(ab_stacks));
	a = init_buffer_a(unordered, max_size);
	b = init_buffer_b(max_size);
	ab_stacks->a = a;
	ab_stacks->b = b;

	return (ab_stacks);
}