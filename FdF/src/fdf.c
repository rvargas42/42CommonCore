/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:33 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/28 11:32:43 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	valid_file(char **args)
{
	if (strncmp(".fdf", &args[1][strlen(args[1])-4],5) != 0)
		return (0);
	return (1);
}

static void	check_args(int argn, char **args)
{
	if (argn != 2)
		throw_error(22, "Program should receive 1 file.fdf");
	if (!valid_file(args))
		throw_error(22, "File should be .fdf extension type");
}

void	set_title(t_map *map, char **args)
{
	char	*title;
	
	title = ft_strtrim(args[1], ".fdf");
	map->title = title;
}

int check_line_chars(char **line)
{
	int		i;
	char	c;

	i = 0;
	while ((c = (*line)[i]))
	{
		if (ft_isalpha(c))
			c = ft_toupper(c);
		ft_printf("%c\n", c);
		if ((c < '0' || c > '9') && (c < 'A' || c > 'F') && c != ' ')
		{
			if (c != ',' && c != '+' && c != '-' && c != '\n')
				throw_error(22, "Not valid characters");
		}
		i++;
	}
	return (0);
}

char	*write_data(char **line)
{
	char 	*slot;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while ((*line)[i] == ' ')
		i++;
	*line += i;
	while ((*line)[len] && (*line)[len] != ' ')
		len++;
	slot = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		slot[i] = (*line)[i];
		i++;
	}
	slot[i] = '\0';
	*line += len;
	return (slot);
}

char	**write_line(char **line, t_map *m)
{
	char	**new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char *) * (m->cols + 1));
	if (!new_line)
		return (NULL);
	while (i < m->cols)
	{
		new_line[i] = write_data(line);
		ft_printf("new_line: %s\n", new_line[i]);
		i++;
	}
	return (new_line);
}

void	set_file_data(char **args, t_map	*m)
{
	char	*line;
	char	***data;
	int		i;

	data = malloc(sizeof(char **) * (m->rows + 1));
	i = 0;
	if (m->file_desc == -1)
		throw_error(errno, "cannot open this file");
	line = get_next_line(m->file_desc);
	while (line)
	{
		if (line == NULL)
			throw_error(errno, "Error reading file");
		else
		{
			data[i] = write_line(&line, m); //REMINDER: liberar cada linea despues al liberar la estructura
			for (int j = 0; j < 10; j++)
				ft_printf("line: %s\n", data[i][j]);
			i++;
		}
		line = get_next_line(m->file_desc);
	}
	free(line);
	m->file_data = data;
}

t_map	*init_map(int argn, char **args)
{
	t_map	*m;

	m = malloc(sizeof(t_map *));
	if (!m)
		return (NULL);
	m->file_path = args[1];
	m->file_desc = open(args[1], O_RDONLY); //REMINDER: Close()
	m->mlx = mlx_init();
	m->title = ft_strtrim(args[1], ".fdf");
	set_rows_cols(m);
	set_matrix(m);
	set_file_data(args, m);
	ft_printf("rows = %d\n", m->rows);
	ft_printf("cols = %d\n", m->cols);
	return (m);
}

int	main(int argn, char **args)
{
	t_map	*map;

	check_args(argn, args);
	map = init_map(argn, args);
	if (!map)
		return (-1);
	// for (int i = 0; i < map->rows; i++)
	// 	ft_printf("%s", map->file_data[i]);
	
	return (0);
}