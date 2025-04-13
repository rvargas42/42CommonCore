/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:02:35 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 16:30:50 by ravargas         ###   ########.fr       */
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
	int		offset;
	char	*dest;
	t_data	*img;

	img = m->img;
	offset = m->line->y * img->len + m->line->x * (img->bit_per_pix / 8);
	dest = img->addr + offset;
	calculate_color(m, p1, p2);
	*(unsigned *) dest = m->line->color;
}

void	draw_bg(t_map *m)
{
	t_point	*p11;
	t_point	*p12;
	t_point	*p21;
	t_point	*p22;

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
	t_point	*p1;
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
