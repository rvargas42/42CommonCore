/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:16:19 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 13:46:45 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf/inc/ft_printf.h"
# include "libft/inc/libft.h"

//buffer to store data
typedef struct s_cbuffer
{
	int	*head;
	int	*tail;
	int	*content;
	int	max_size;
}		t_stack;

//main structure that stores both stacks
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

int			array_len(int *array);
int			matrix_dim(char **mat);
void		print_unordered(int	*nums);
t_stacks	*init_stacks(int **unordered, int max_size);
int			*unordered_nums(int argn, char const *args);
void		free_all(t_stacks *ab_stacks);

#endif