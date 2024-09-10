/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:02:35 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/09 12:27:05 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	digital_diff(t_map *m, float x1, float y1, float x2, float y2)
{
	float	px;
	float	py;
	float	delta_x;
	float	delta_y;
	int		pixels;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	pixels = sqrt((pow(delta_x, 2)) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	px = x1;
	py = y1;
	while (pixels)
	{
		pixel_to_image(m->img, px, py, 0x00ff0000);
		px += delta_x;
		py += delta_y;
		--pixels;
	}
}

void	pixel_to_image(t_data *img, float x, float y, int color)
{
	int		offset;
	char	*dest;

	offset = y * img->len + x * (img->bit_per_pix / 8);
	dest = img->addr + offset;
	*(unsigned *) dest = color;
}

void	bresenham_draw(t_map *m, float x1, float y1, float x2, float y2)
{
	int	m_new;
	int	e_new;
	int	x;
	int	y;

	x = x1;
	y = y1;
	m_new = 2 * (y2 - y1);
	e_new = m_new - (x2 - x1);
	while (x <= x2)
	{
		pixel_to_image(m->img, x, y, 0x00ff0000);
		e_new += m_new;
		if (e_new >= 0)
		{
			y++;
			e_new -= 2 * (x2 - x1);
		}
		x++;
	}
}

void	draw_bg(t_map *m)
{
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;
	t_point	*p4;

	p1 = m->map[0][0];
	p2 = m->map[0][m->cols - 1];
	p3 = m->map[m->rows - 1][0];
	p4 = m->map[m->rows - 1][m->cols - 1];
	digital_diff(m, p1->x, p1->y, p2->x, p2->y);
	digital_diff(m, p1->x, p1->y, p3->x, p3->y);
	digital_diff(m, p2->x, p2->y, p4->x, p4->y);
	digital_diff(m, p3->x, p3->y, p4->x, p4->y);
}

void draw_point(t_map *m, t_point *p1, t_point *p2,  t_point *p3)
{
	
	digital_diff(m, p1->x, p1->y, p2->x, p2->y);
	digital_diff(m, p1->x, p1->y, p3->x, p3->y);
}

void	draw_map(t_map *m)
{
	int		i;
	int		j;
	t_point *p1;
	t_point	*p2;
	t_point	*p3;


	i = 0;
	//draw_bg(m);
	while (i + 1 < m->rows)
	{
		j = 0;
		while (j + 1 < m->cols)
		{
			p1 = m->map[i][j];
			p2 = m->map[i][j + 1];
			p3 = m->map[i + 1][j];
			draw_point(m, p1, p2, p3);
			j += 1;
		}
		draw_point(m, p1, p2, p3);
		i += 1;
	}
}