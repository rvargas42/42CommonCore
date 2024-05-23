/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:36:09 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 11:52:52 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	matrix_dim(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

