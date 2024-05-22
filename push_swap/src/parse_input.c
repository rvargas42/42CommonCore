/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:53:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/22 13:08:12 by ravargas         ###   ########.fr       */
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

static void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		printf("%s", args[i++]);
}

static void	copy_args(char	**nums, int *clean_arr)
{
	int			i;
	int			d;

	i = 0;
	while (nums[i++])
	{
		d = ft_atoi(nums[i]);
		
	}
}

int	*unordered_nums(int argn, char const *args)
{
	char		**nums;
	int			*clean_arr;

	nums = ft_split(args, ' ');
	contains_dup(nums);
	contains_digit(nums);
	clean_arr = malloc(sizeof(int) * (argn-1));
	if (!clean_arr)
		exit(-1);
	//copy_args(nums, clean_array);
	// init_stacks(clean_arr);
	ft_printf("test");
	return (clean_arr);
}