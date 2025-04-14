/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:23:38 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/14 18:45:39 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_program(t_map *m)
{
	if (!m)
		return ;
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
	if (m->mlx)
	{
		mlx_destroy_display(m->mlx);
		free(m->mlx);
	}
	free(m->line);
	free(m->title);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

void	free_map(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	if (!m->map)
		return ;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			free(m->map[y][x]->color);
			free(m->map[y][x]);
			x++;
		}
		free(m->map[y]);
		y++;
	}
	free(m->map);
}

void	free_file_data(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	if (!m->file_data)
		return ;
	while (m->file_data[y] != NULL)
	{
		x = 0;
		while (m->file_data[y][x] != NULL)
		{
			free(m->file_data[y][x]);
			x++;
		}
		free(m->file_data[y]);
		y++;
	}
	free(m->file_data);
}

void	clean_program(t_map *map)
{
	if (!map)
		return ;
	free_file_data(map);
	free_map(map);
	if (map->img)
	{
		if (map->img->image)
			mlx_destroy_image(map->mlx, map->img->image);
		free(map->img);
	}
	free_program(map);
	free(map);
	return ;
}
