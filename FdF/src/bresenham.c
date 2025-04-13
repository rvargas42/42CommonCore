/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:23:36 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 16:29:38 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	slope(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

void	update_error(t_map *m)
{
	int	e2;

	e2 = 2 * (m->line->err);
	if (e2 > -m->line->dy)
	{
		m->line->err -= m->line->dy;
		m->line->x += m->line->sx;
	}
	if (e2 < m->line->dx)
	{
		m->line->err += m->line->dx;
		m->line->y += m->line->sy;
	}
}

void	set_line(t_map *m, t_point *p1, t_point *p2)
{
	int	dx;
	int	dy;

	if (!m->line)
		m->line = malloc(sizeof(t_line));
	if (!m->line)
		exit_program_w_error(m, ENOMEM);
	dx = abs(p2->isox - p1->isox);
	dy = abs(p2->isoy - p1->isoy);
	m->line->p1 = p1;
	m->line->p2 = p2;
	m->line->dx = dx;
	m->line->dy = dy;
	m->line->err = dx - dy;
	m->line->x = p1->isox;
	m->line->y = p1->isoy;
	m->line->sx = slope(p1->isox, p2->isox);
	m->line->sy = slope(p1->isoy, p2->isoy);
}

void	bresenham(t_map *m, t_point *p1, t_point *p2)
{
	set_line(m, p1, p2);
	while (m->line->x != p2->isox && m->line->y != p2->isoy)
	{
		if (m->line->x <= m->size_x && m->line->y <= m->size_y)
			pixel_to_image(m, p1, p2);
		update_error(m);
	}
}
