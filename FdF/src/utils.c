/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:59:23 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/28 10:17:14 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* ------------------------- Get max number of cols ------------------------- */

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
		if (cols == -1) return (-1);
		free(line);
		line = get_next_line(map->file_desc);
	}
	close(map->file_desc);
	map->file_desc = open(map->file_path, O_RDONLY);
	return (0);
}
