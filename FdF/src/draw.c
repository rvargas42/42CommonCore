/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:02:35 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/05 15:59:32 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	calculate_color(t_map *m, t_point *p1, t_point *p2)
{
	t_color	color;
	double	t;
	int		new_color;

	t = point_weight(m->line->x, m->line->y, p1, p2);
	color.r = p1->color->r + (p2->color->r - p1->color->r) * t;
	color.g = p1->color->g + (p2->color->g - p1->color->g) * t;
	color.b = p1->color->b + (p2->color->b - p1->color->b) * t;
	new_color = (color.r << 16) | (color.g << 8) | color.b;
	m->line->color = new_color;
}

void	pixel_to_image(t_map *m, t_point *p1, t_point *p2)
{
	int     offset;
	char    *dest;
	t_data	*img;

	img = m->img;
	offset = m->line->y * img->len + m->line->x * (img->bit_per_pix / 8);
	dest = img->addr + offset;
	calculate_color(m, p1, p2);
	*(unsigned *) dest = m->line->color;
}


int slope(int start, int end)
{
	if (start < end)
		return 1;
	else
		return -1;
}

void	update_error(t_map *m)
{
	int e2;

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

	if (!m->line) m->line = malloc(sizeof(t_line));
	if (!m->line) return;
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

void	draw_bg(t_map *m)
{
	t_point *p11;
	t_point	*p12;
	t_point	*p21;
	t_point *p22;

	p11 = m->map[0][0];
	p12 = m->map[0][m->cols - 1];
	p21 = m->map[m->rows - 1][0];
	p22 = m->map[m->rows - 1][m->cols - 1];
	bresenham(m, p11, p12);
	bresenham(m, p11, p21);
	bresenham(m, p21, p22);
	bresenham(m, p12, p22);
}

void	draw_map(t_map *m)
{
	int		i;
	int		j;
	t_point *p1;
	t_point	*p2;
	t_point	*p3;


	i = 0;
	while (i + 1 < m->rows)
	{
		j = 0;
		while (j + 1 < m->cols)
		{
			p1 = m->map[i][j];
			p2 = m->map[i][j + 1];
			p3 = m->map[i + 1][j];
			bresenham(m, p1, p2);
			bresenham(m, p1, p3);
			j += 1;
		}
		i += 1;
	}
}