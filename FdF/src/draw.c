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

void pixel_to_image(t_data *img, int x, int y, int color)
{
    int     offset;
    char    *dest;

    offset = y * img->len + x * (img->bit_per_pix / 8);
    dest = img->addr + offset;
    *(unsigned *) dest = color;
}

int calculate_color(int x, int y, t_point *p1, t_point *p2)
{
	double	t;
	int		delta_x;
	int		delta_y;
	t_color	color;
	int		new_color;

	delta_x = p2->isox - p1->isox;
	delta_y = p2->isoy - p1->isoy;
	t = point_weight(x, y, p1, p2);
	color.r = p1->color.r + (p2->color.r - p1->color.r) * t;
	color.g = p1->color.g + (p2->color.g - p1->color.g) * t;
	color.b = p1->color.b + (p2->color.b - p1->color.b) * t;
	new_color = (color.r << 16) | (color.g << 8) | color.b;
	return (new_color);
}

void plot_pixel(t_map *m, int x, int y, t_point *p1, t_point *p2)
{
	int	new_color;

	new_color = calculate_color(x, y, p1, p2);
    pixel_to_image(m->img, x, y, new_color);
}

int calculate_step(int start, int end)
{
    if (start < end)
        return 1;
    else
        return -1;
}

void update_error(int *err, int *x, int *y, int dx, int dy, int sx, int sy)
{
    int e2;

	e2 = 2 * (*err);
    if (e2 > -dy)
    {
        *err -= dy;
        *x += sx;
    }

    if (e2 < dx)
    {
        *err += dx;
        *y += sy;
    }
}

void bresenham(t_map *m, t_point *p1, t_point *p2)
{
    int dx = abs(p2->isox - p1->isox);
    int dy = abs(p2->isoy - p1->isoy);
    int sx = calculate_step(p1->isox, p2->isox);
    int sy = calculate_step(p1->isoy, p2->isoy);
    int err = dx - dy;

    int x = p1->isox;
    int y = p1->isoy;

    while (x != p2->isox && y != p2->isoy)
    {
        plot_pixel(m, x, y, p1, p2);
        update_error(&err, &x, &y, dx, dy, sx, sy);
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