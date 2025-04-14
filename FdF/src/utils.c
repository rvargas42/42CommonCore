/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:59:23 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/14 17:56:36 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_min_max(t_map *m)
{
	m->min_max.min_x = INT_MAX;
	m->min_max.min_y = INT_MAX;
	m->min_max.min_z = INT_MAX;
	m->min_max.max_x = INT_MIN;
	m->min_max.max_y = INT_MIN;
	m->min_max.max_z = INT_MIN;
}

void	update_min_max(t_map *m, t_point *p)
{
	if (p->x > m->min_max.max_x)
		m->min_max.max_x = p->x;
	if (p->y > m->min_max.max_y)
		m->min_max.max_y = p->y;
	if (p->z > m->min_max.max_z)
		m->min_max.max_z = p->z;
	if (p->x < m->min_max.min_x)
		m->min_max.min_x = p->x;
	if (p->y < m->min_max.min_y)
		m->min_max.min_y = p->y;
	if (p->z < m->min_max.min_x)
		m->min_max.min_z = p->z;
}

void	set_min_max(t_map *m)
{
	int		y;
	int		x;
	t_point	*p;

	y = 0;
	init_min_max(m);
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			p = m->map[y][x];
			update_min_max(m, p);
			x++;
		}
		y++;
	}
	return ;
}

int	set_cols(char *line, t_map *map)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\n'))
			n++;
		i++;
	}
	if (map->cols != 0 && (map->cols != n))
		return (-1);
	if (map->cols < n)
		map->cols = n;
	return (n);
}

int	set_rows_cols(t_map *map)
{
	char	*line;
	int		fd;
	int		cols;

	map->cols = 0;
	map->rows = 0;
	line = get_next_line(map->file_desc);
	while (line != NULL)
	{
		map->rows++;
		cols = set_cols(line, map);
		if (cols == -1)
			return (-1);
		free(line);
		line = get_next_line(map->file_desc);
	}
	close(map->file_desc);
	free(line);
	map->file_desc = open(map->file_path, O_RDONLY);
	return (0);
}
