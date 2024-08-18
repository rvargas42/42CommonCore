/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:33 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/18 20:43:57 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	read_file(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	close(fd);
	return ;
}

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

void	process_line(char **line)
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
}

void	check_file_data(char **args)
{
	int		fd;
	char	*line;

	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		throw_error(errno, "cannot open this file");
	while ((line = get_next_line(fd)))
	{
		if (line == NULL && errno != 0)
			throw_error(errno, "Error reading file");
		else
			process_line(&line);
	}
}

t_map	*init_map(int argn, char **args)
{
	t_map	*m;

	m = malloc(sizeof(t_map *));
	if (!m)
		return (NULL);
	m->file_path = args[1];
	m->file_desc = open(m->file_path, O_RDONLY);
	m->mlx = mlx_init();
	m->title = ft_strtrim(args[1], ".fdf");
	set_rows_cols(m);
	set_matrix(m);
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
	//ft_printf("rows = %d", map->rows);
	
	return (0);
}