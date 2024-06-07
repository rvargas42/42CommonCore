/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:55 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/03 11:45:40 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	*number_set(int length)
{
	int	*set;

	set = ft_calloc(length, sizeof(int));
	if (!set)
		return (NULL);
	return (set);
}

static void	check_dups(int	**arr, int **set)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (*(arr)[i++])
	{
		j = 0;
		while (*(set)[j++])
		{
			if (*(set)[j] == *(arr)[i])
			{
				free(*set);
				free(*arr);
				*arr = NULL;
				return ;
			}
			else
				*(set)[k++] = *(arr)[i];
		}
	}
}
void	check_array(int **clean_arr)
{
	int	*set;
	int	*arr;
	int	i;
	int	j;

	i = 0;
	arr = *(clean_arr);
	set = number_set(array_len(arr));
	if (!set)
		return ;
	else
		check_dups(&arr, &set);
}
