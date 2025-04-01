/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 15:45:46 by ravargas          #+#    #+#             */
/*   Updated: 2025-04-01 15:45:46 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	move_x(t_map *m, int amount)
{
	int	y;
	int	x;
	int	new_x;

	y = 0;
	while (m->map[y] != NULL)
	{
		x = 0;
		while (m->map[y][x])
		{
			new_x = m->map[y][x]->x + amount;
			m->map[y][x]->x = new_x;
			x++;
		}
		y++;
	}

}

void	move_y(t_map *m, int amount)
{
	int	y;
	int	x;
	int	new_y;

	y = 0;
	while (m->map[y] != NULL)
	{
		x = 0;
		while (m->map[y][x])
		{
			new_y = m->map[y][x]->y + amount;
			m->map[y][x]->x = new_y;
			x++;
		}
		y++;
	}

}