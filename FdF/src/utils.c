/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:59:23 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/18 20:30:57 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* ------------------------- Get max number of cols ------------------------- */
void	set_cols(char *line, t_map *map)
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
	if (map->cols < n)
		map->cols = n;
}

void	set_rows_cols(t_map *map)
{
	char	*line;
	int		fd;
	int		rows;

	rows = 0;
	map->cols = 0;
	line = get_next_line(map->file_desc);
	while (line != NULL)
	{
		rows++;
		set_cols(line, map);
		free(line);
		line = get_next_line(map->file_desc);
	}
	close(map->file_desc);
	map->rows = rows;
}
