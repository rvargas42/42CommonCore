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

#include "../../inc/push_swap.h"

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
	while (mat[i] != NULL)
		i++;
	return (i);
}

int	contains_duplicates(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	if (!nums)
		return (1);
	while (i < len)
	{
		j = 1;
		while (i + j < len)
		{
			if (nums[i] == nums[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	*copy_numbers(char **nums, int **array, int len)
{
	long int	d;
	int			i;

	i = 0;
	while (i < len)
	{
		d = ft_atoi(nums[i]);
		if (d < INT_MIN || d > INT_MAX)
		{
			free(*array);
			*array = NULL;
			return (NULL);
		}
		(*array)[i] = (int) d;
		i++;
	}
	(*array)[i] = '\0';
	return (array);
}
