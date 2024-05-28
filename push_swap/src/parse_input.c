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

#include "../inc/push_swap.h"

static void	contains_digit(char	**arg)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while ((c=arg[i][j]))
		{
			if (ft_isalpha(arg[i][j]))
				exit(-1);
			if (ft_isdigit(arg[i][j]))
			{
				if (arg[i][j+1] && (arg[i][j+1] == '+' || arg[i][j+1] == '-'))
					exit(-1);
			}
			if (!ft_isdigit(c) && (c != '-' && c != '+'))
				exit(-1);
			j++;
		}
		i++;
	}
}
static void	contains_dup(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i+1] != NULL)
	{
		j = 0;
		if (ft_atoi(nums[i]) == ft_atoi(nums[i+1]))
			exit(-1);
		i++;
	}
}

static int	*build_array(char **nums)
{
	int	i;
	int	d;
	int	size;
	int	*array;

	i = 0;
	size = matrix_dim(nums);
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (nums[i] != NULL)
	{
		d = ft_atoi(nums[i]);
		array[i] = d;
		i++;
	}
	return (array);
}

void	free_split(char **nums)
{
	int	i;

	i = 0;
	while (*(nums + i))
	{
		free(*(nums + i));
		i++;
	}
	free(nums);
}
//returns the array that will be inserted into cbuffer
int	*unordered_nums(int argn, char const *args)
{
	char		**nums;
	int			*clean_arr;

	nums = ft_split(args, ' ');
	contains_dup(nums);
	contains_digit(nums);
	clean_arr = build_array(nums);
	if (!clean_arr)
	{
		free(clean_arr);
		exit(-1);
	}
	free_split(nums);
	return (clean_arr);
}