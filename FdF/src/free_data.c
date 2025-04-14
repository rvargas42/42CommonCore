/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:23:38 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:01:46 by ravargas         ###   ########.fr       */
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
	free(m->file_data);
	free(m->title);
}


void	free_img(t_map *m)
{
	if (m->img)
	{
		if (m->img->image)
			mlx_destroy_image(m->mlx, m->img->image);
		free(m->img);
	}
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
}

void	clean_program(t_map *map)
{
	if (!map)
		return ;
	free_file_data(map);
	free_map(map);
	free_img(map);
	free_program(map);
	free(map);
	return ;
}
