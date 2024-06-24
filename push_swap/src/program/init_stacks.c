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
	if (!a)
		return (NULL);
	a->content = *unordered;
	a->id = 'a';
	a->head = 0;
	a->tail = max_size - 1;
	a->entries = max_size;
	a->max_size = max_size;
	a->moves = 0;
	return (a);
}

static void *init_buffer_b(int max_size)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->content = (int *)calloc(max_size + 1, sizeof(int));
	b->id = 'b';
	b->head = max_size - 1;
	b->tail = max_size - 1;
	b->entries = 0;
	b->max_size = max_size;
	b->moves = 0;
	return (b);
}

t_stacks	*init_stacks(int **unordered, int max_size)
{
	t_stacks	*ab_stacks;
	t_stack		*b;
	t_stack		*a;
	
	ab_stacks = malloc(sizeof(t_stacks));
	if (!ab_stacks)
		return (NULL);
	a = init_buffer_a(unordered, max_size);
	b = init_buffer_b(max_size);
	if (!a || !b)
	{
		free_all(ab_stacks);
		exit(EXIT_FAILURE);
	}
	ab_stacks->a = a;
	ab_stacks->b = b;
	return (ab_stacks);
}