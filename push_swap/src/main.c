/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/22 13:13:47 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argn, char const **argv)
{
	int		*unordered;
	stacks	st_stacks;

	if (argn != 2)
		exit(-1);

	unordered = unordered_nums(argn, argv[1]);
	st_stacks = init_stacks(unordered);
	push_swap(st_stacks);
	//print_unordered(unordered);
	
	return (1);
}