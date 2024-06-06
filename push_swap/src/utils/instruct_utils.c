/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:43:48 by ravargas          #+#    #+#             */
/*   Updated: 2024/06/06 18:54:59 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	repeat_instruct(int n, int instruct)
{
	if (instruct == 0)
		repeat_swap(n);
	if (instruct == 1)
		repeat_ss(n);
	if (instruct == 2)
		repeat_push(n);
	if (instruct == 3)
		repeat_rotate(n);
	if (instruct == 4)
		repeat_rr(n);
	if (instruct == 5)
		repeat_rvrotate(n);
	if (instruct == 6)
		repeat_rvrr(n);
}