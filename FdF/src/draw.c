/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:02:35 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/11 12:23:24 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	digital_diff(t_map *m, t_point *p1, t_point *p2)
{
	int	px;
	int	py;
	int	delta_x;
	int	delta_y;
	int	pixels;

	delta_x = p2->x - p1->x;
	delta_y = p2->y - p1->y;
	pixels = sqrt((pow(delta_x, 2)) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	px = p1->isox;
	py = p1->isoy;
	while (pixels)
	{
		pixel_to_image(m->img, px, py, 0xfefffc);
		px += delta_x;
		py += delta_y;
		--pixels;
	}
}

void	pixel_to_image(t_data *img, int x, int y, int color)
{
	int		offset;
	char	*dest;

	offset = y * img->len + x * (img->bit_per_pix / 8);
	dest = img->addr + offset;
	*(unsigned *) dest = create_trgb(3, 125, 100, 0);
}

void	get_line_pixels(t_map *m, t_point *p1, t_point *p2)
{
	m->pix_x = p2->x - p1->x;
	m->pix_y = p2->y - p1->y;
}

void	bresenham_draw(t_map *m, t_point *p1, t_point *p2)
{
	int	m_new;
	int	e_new;
	int	x;
	int	y;

	x = p1->isox;
	y = p1->isoy;
	m_new = 2 * (p2->isoy - p1->isoy);
	e_new = m_new - (p2->isox - p1->isox);
	get_line_pixels(m, p1, p2);
	while (x <= m->pix_x || (m->pix_x == 0 && y <= m->pix_y))
	{
		pixel_to_image(m->img, x, y, 0xfefffc);
		e_new += m_new;
		if (e_new >= 0)
		{
			y++;
			e_new -= 2 * (p2->isox - p1->isox);
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
	digital_diff(m, p1, p2);
	digital_diff(m, p1, p3);
	digital_diff(m, p2, p4);
	digital_diff(m, p3, p4);
}

void draw_line(t_map *m, t_point *p1, t_point *p2)
{
	digital_diff(m, p1, p2);
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
			draw_line(m, p1, p2);
			draw_line(m, p1, p3);
			j += 1;
		}
		i += 1;
	}
}