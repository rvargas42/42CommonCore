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

void	digital_diff(t_map *m, t_point *p1, t_point *p2)
{
	int		px;
	int		py;
	int		delta_x;
	int		delta_y;
	double	pixels;

	delta_x = abs(p2->sx - p1->sx);
	delta_y = abs(p2->sy - p1->sy);
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

void plot_pixel(t_map *m, int x, int y)
{
    pixel_to_image(m->img, x, y, 0xfefffc);
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
    int e2 = 2 * (*err);

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

void draw_line(t_map *m, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = calculate_step(x0, x1);
    int sy = calculate_step(y0, y1);
    int err = dx - dy;

    while (1)
    {
        plot_pixel(m, x0, y0);

        if (x0 == x1 && y0 == y1)
            break;

        update_error(&err, &x0, &y0, dx, dy, sx, sy);
    }
}

void bresenham(t_map *m, t_point *p1, t_point *p2)
{
    draw_line(m, p1->isox, p1->isoy, p2->isox, p2->isoy);
}

void	get_line_pixels(t_map *m, t_point *p1, t_point *p2)
{
	m->pix_x = p2->x - p1->x;
	m->pix_y = p2->y - p1->y;
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