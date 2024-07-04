/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:53:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/07/04 10:54:22 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	check_chars(char c, char cnext)
{
	if (ft_isalpha(c))
		return (-1);
	if ((c == '-' || c == '+') && cnext == '\0')
		return (-1);
	if ((c == '-' || c == '+') && (cnext == '-' || cnext == '+'))
		return (-1);
	if (ft_isdigit(c) && cnext != '\0')
	{
		if (cnext == '+' || cnext == '-')
			return (-1);
	}
	if (!ft_isdigit(c) && (c != '-' && c != '+'))
		return (-1);
	return (1);
}

static int	contains_digit(const char **arg, int len)
{
	int		i;
	int		j;

	i = 0;
	if (len <= 1)
		return (-1);
	while (i < len)
	{
		if (arg[i] == NULL)
			return (-1);
		if (ft_strlen(arg[i]) <= 1 && !ft_isdigit(arg[i][0]))
			return (-1);
		j = 0;
		while (arg[i][j])
		{
			if (check_chars(arg[i][j], arg[i][j + 1]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	*build_array(char const **nums, int len)
{
	int			i;
	int			*array;

	i = 0;
	array = malloc((len + 1) * sizeof(int));
	if (!array || contains_digit(++nums, len) == -1)
		return (NULL);
	while (i < len)
	{
		if (ft_atoi(nums[i]) < INT_MIN || ft_atoi(nums[i]) > INT_MAX)
		{
			free(array);
			return (NULL);
		}
		array[i] = (int) ft_atoi(nums[i]);
		i++;
	}
	array[i] = '\0';
	if (contains_duplicates(array, len) == 1)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

static int	*build_from_one(char const *s, int len)
{
	int			*array;
	char		**split;

	split = ft_split((const char *) s, ' ');
	if (contains_digit((const char **) split, len) == -1)
	{
		free_split(split);
		return (NULL);
	}
	array = malloc((len + 1) * sizeof(int));
	if (!array)
	{
		free_split(split);
		return (NULL);
	}
	copy_numbers(split, &array, len);
	free_split(split);
	if (contains_duplicates(array, len) == 1 || array == NULL)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	*unordered_nums(int argn, char const **args, int stack_size)
{
	int			*clean_arr;

	if (argn == 2)
		clean_arr = build_from_one(args[1], stack_size);
	else
		clean_arr = build_array(args, stack_size);
	if (clean_arr == NULL)
	{
		write(2, "Error\n", 7);
		free(clean_arr);
		exit(-1);
	}
	return (clean_arr);
}
