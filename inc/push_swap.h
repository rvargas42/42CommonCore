/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:16:19 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/22 13:21:06 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf/inc/ft_printf.h"
#include "libft/inc/libft.h"

typedef struct	s_d_llist
{
	struct s_d_llist	*prev;
	int					content;
	struct s_d_llist	*next;
}						d_llist;

typedef struct	s_stack
{
	d_llist	**top;
	int		max_size;
}			ps_stack;

typedef struct s_stacks
{
	ps_stack	*a;
	ps_stack	*b;
}				stacks;

void	*unordered_nums(int argn, char const *args);
stacks	init_stacks(int *unordered);