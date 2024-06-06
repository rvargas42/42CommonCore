/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:17 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:24 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int main(int argn, char const **argv)
{
	int			*unordered;
	t_stacks	*stacks;

	if (argn < 2)
		exit(EXIT_SUCCESS);
	unordered = unordered_nums(argn, argv);
	stacks = init_stacks(&unordered, array_len(unordered));
	test_instructions(stacks);
	//push_swap(st_stacks)
	free_all(stacks); //TODO: function that frees all data
	return (1);
}