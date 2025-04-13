/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:37:59 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:12:29 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	normalize_point(t_map *m, int x, int y)
{
	t_point	*p;
	float	x_new;
	float	y_new;
	float	z_scale;

	p = m->map[y][x];
	p->sx = p->x * m->scale.scalef * 0.50 + (m->size_x / 2);
	p->sy = p->y * m->scale.scalef * 0.50;
	p->sz = p->z * m->scale.scalez;
	p->isox = p->sx;
	p->isoy = p->sy;
}

void	normalize_and_project(t_map *m)
{
	int		y;
	int		x;

	y = 0;
	while (m->map[y] != NULL)
	{
		x = 0;
		while (m->map[y][x])
		{
			normalize_point(m, x, y);
			isometric(m, m->map[y][x], 0.5);
			x++;
		}
		y++;
	}
}

void	add_color_channels(t_point **point, char *color_data)
{
	int		color;
	t_color	*color_t;

	if (point == NULL || color_data == NULL)
		return ;
	color_t = malloc(sizeof(t_color));
	color = ft_atoi_hex(color_data);
	color_t->r = (color >> 16) & 0xFF;
	color_t->g = (color >> 8) & 0xFF;
	color_t->b = (color) & 0xFF;
	(*point)->color = color_t;
}

void	add_point(t_map *m, int y, int x)
{
	char	*data;
	t_point	*point;
	int		sep;

	sep = 0;
	data = m->file_data[y][x];
	point = malloc(sizeof(t_point));
	if (ft_strchr(data, ','))
	{
		sep = ft_strchr(data, ',') - data;
		if (data + sep + 1)
			add_color_channels(&point, data + sep + 1);
	}
	else
		add_color_channels(&point, "0x00FF04");
	point->x = x;
	point->y = y;
	point->z = (int) ft_atoi(ft_split(data, ',')[0]);
	m->map[y][x] = point;
}

void	set_point_data(t_map *m)
{
	int		y;
	int		x;
	t_point	**map;

	y = 0;
	x = 0;
	m->map = malloc(sizeof(t_point *) * (m->rows));
	if (!map)
		return ;
	while (m->file_data[y] != NULL)
	{
		x = 0;
		m->map[y] = malloc(sizeof(t_point) * (m->cols));
		while (m->file_data[y][x])
		{
			add_point(m, y, x);
			x++;
		}
		m->map[y][x] = NULL;
		y++;
	}
	m->map[y] = NULL;
}
