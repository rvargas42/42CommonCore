/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:53:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/23 12:47:08 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	contains_digit(const char **arg)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while ((c=arg[i][j]))
		{
			if (ft_isalpha(arg[i][j]))
				return (-1);
			if (ft_isdigit(arg[i][j]))
			{
				if (arg[i][j+1] && (arg[i][j+1] == '+' || arg[i][j+1] == '-'))
					return (-1);
			}
			if (!ft_isdigit(c) && (c != '-' && c != '+'))
				return (-1);
			j++;
		}
		i++;
	}
}

static int	*build_array(char const **nums)
{
	int	i;
	int	d;
	int	size;
	int	*array;

	i = 0;
	size = matrix_dim((char **) ++nums);
	array = malloc((size) * sizeof(int));
	if (!array || contains_digit(nums) == -1)
		return (NULL);
	while (nums[i] != NULL)
	{
		d = ft_atoi(nums[i]);
		array[i] = d;
		i++;
	}
	if (contains_duplicates(array) == 1)
		return (NULL);
	array[i] = '\0';
	return (array);
}

//returns the array that will be inserted into cbuffer
int	*unordered_nums(int argn, char const **args)
{
	int			*clean_arr;

	clean_arr = build_array(args);
	if (clean_arr == NULL)
	{
		write(2, "Error\n", 7);
		free(clean_arr);
		exit(-1);
	}
	return (clean_arr);
}