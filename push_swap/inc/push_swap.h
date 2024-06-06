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

typedef struct s_cbuffer
{
	char	id;
	int		head;
	int		tail;
	int		*content;
	int		entries;
	int		max_size;
}			t_stack;

typedef struct s_stacks
{
	int		instruction;
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

# define INSTRUCT_SWAP "s"
# define INSTRUCT_SS "ss"
# define INSTRUCT_PUSH "p"
# define INSTRUCT_ROTATE "r"
# define INSTRUCT_RR "rr"
# define INSTRUCT_RVR "rr"
# define INSTRUCT_RVRR "rrr"

int			array_len(int *array);
int			matrix_dim(char **mat);
void		print_stacks(t_stacks *stacks);
void		print_unordered(int	*nums);
void		print_buffer(t_stack *s);
t_stacks	*init_stacks(int **unordered, int max_size);
int			*unordered_nums(int argn, char const **args);
int			contains_duplicates(int *nums);
void		free_all(t_stacks *ab_stacks);
void    	push_stack(t_stack *src, t_stack *dst);
void    	swap_stack(t_stack *s);
void    	rotate_stack(t_stack *s);
void    	reverse_rotate(t_stack *s);
void    	ss(t_stacks *stacks);
void    	rr(t_stacks *stacks);
void    	rrr(t_stacks *stacks);
int			is_full(t_stack *s);
int			is_empty(t_stack *s);
int			keep_running(t_stack *s);
void		test_instructions(t_stacks *stacks);

#endif