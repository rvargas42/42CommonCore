/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:53:16 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/28 12:30:36 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_mean(t_stack *s)
{
	int	sum;
	int	n;

	sum = 0;
	n = 0;
	while (n < s->entries)
	{
		sum += s->content[s->head + n];
		n++;
	}
	if (n == 0 || sum == 0)
		return (0);
	return (sum / n);
}
