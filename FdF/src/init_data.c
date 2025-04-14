/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:32:33 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:20:28 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_image(t_map *m)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->image = mlx_new_image(m->mlx, m->size_x, m->size_y);
	data->addr = mlx_get_data_addr(data->image, &data->bit_per_pix, \
		&data->len, &data->endian);
	m->img = data;
}

void	set_scale_factor(t_map *m)
{
	set_min_max(m);
	m->scale.scalex = m->size_x / (m->cols);
	m->scale.scaley = m->size_y / (m->rows);
	m->scale.scalez = (m->cols / m->rows);
	m->scale.scalef = fmin(m->scale.scalex, m->scale.scaley);
}

void	init_struct_pointers(t_map *m)
{
	m->win = NULL;
	m->mlx = NULL;
	m->file_path = NULL;
	m->file_data = NULL;
	m->title = NULL;
	m->img = NULL;
	m->map = NULL;
	m->line = NULL;
}

t_map	*init_map(int argn, char **args)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	if (!m)
		return (NULL);
	init_struct_pointers(m);
	m->file_path = args[1];
	m->file_desc = open(args[1], O_RDONLY);
	m->title = ft_strtrim(args[1], ".fdf");
	m->size_x = 1920;
	m->size_y = 1080;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->size_x, m->size_y, m->title);
	set_image(m);
	check_map(m);
	set_file_data(args, m);
	set_point_data(m);
	set_scale_factor(m);
	return (m);
}
