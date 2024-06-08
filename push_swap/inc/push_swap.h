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
	int		moves;
}			t_stack;

typedef struct s_stacks
{
	int		inst;
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

# define INSTRUCT_SWAP 0
# define INSTRUCT_SS 1
# define INSTRUCT_PUSH 2
# define INSTRUCT_ROTATE 3
# define INSTRUCT_RR 4
# define INSTRUCT_RVR 5
# define INSTRUCT_RVRR 6

int			is_full(t_stack *s);
int			smallest(t_stack *s);
int			is_empty(t_stack *s);
int			mid_point(t_stack *s);
int			array_len(int *array);
int			matrix_dim(char **mat);
int			get_index(int n, t_stack *s);
int			contains_duplicates(int *nums);
int			push_cost(int index, t_stack *s);
int			*unordered_nums(int argn, char const **args);
int			itarget_cost(int index_a, int index_b, t_stacks *ab_stacks);
void		smallest_to_top(t_stack *s);
void		print_stacks(t_stacks *stacks);
void		print_unordered(int	*nums);
void		print_buffer(t_stack *s);
void		free_all(t_stacks *ab_stacks);
void    	push_stack(t_stack *src, t_stack *dst);
void    	swap_stack(t_stack *s);
void    	rotate_stack(t_stack *s);
void    	reverse_rotate(t_stack *s);
void    	ss(t_stacks *stacks);
void    	rr(t_stacks *stacks);
void    	rrr(t_stacks *stacks);
void		repeat_rvrotate(int n, t_stack *s);
void		repeat_rvr(int n, t_stacks *ab_stacks);
void		repeat_rotate(int n, t_stack *s);
void		repeat_rr(int n, t_stacks *ab_stacks);
void		repeat_ss(int n, t_stacks *ab_stacks);
void		repeat_swap(int n, t_stack *s);
void		repeat_push(int n, t_stack *src, t_stack *dst);
void		bubble_sort(t_stacks *ab_stacks);
void		test_instructions(t_stacks *stacks);
t_stacks	*init_stacks(int **unordered, int max_size);

#endif