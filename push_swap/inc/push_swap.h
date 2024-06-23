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
# include <limits.h>
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

int			absol(int n);
int			is_full(t_stack *s);
int			biggest(t_stack *s);
int			smallest(t_stack *s);
int			is_empty(t_stack *s);
int			mid_point(t_stack *s);
int			array_len(int *array);
int			matrix_dim(char **mat);
int			stack_mean(t_stack *s);
int			is_in_a(t_stack *s, int num);
int			get_index(int n, t_stack *s);
int			contains_duplicates(int *nums);
int			closest_up(t_stack *s, int ref, int start, int end);
int			closest_down(t_stack *s, int ref, int start, int end);
int			push_distance(int a, int b, t_stack *src, t_stack *dst);
int			push_cost(int index, t_stack *s);
int			optimum_cost_min(t_stack *s);
int			*unordered_nums(int argn, char const **args);
int			push_target_cost(int ref, int target, t_stack *src, t_stack *dst);
int			push_smallest_bigger(t_stacks *ab);
int			sorted_asc(t_stack *s, int start, int finish);
int			sorted_desc(t_stack *s, int start, int finish);
void		push_number(t_stack *src, t_stack *dst, int n);
void 		insert_number(t_stack *src, t_stack *dst, int ref, int pos);
void		number_to_top(t_stack *s, int number);
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
void		insertion_sort(t_stacks *ab_stacks);
void		insertion_sort_opt(t_stacks *ab);
void		quick_sort(t_stacks *ab_stacks);
void		test_instructions(t_stacks *stacks);
t_stacks	*init_stacks(int **unordered, int max_size);

#endif