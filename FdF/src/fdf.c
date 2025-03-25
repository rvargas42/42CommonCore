/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:33 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/03 12:19:35 by ravargas         ###   ########.fr       */
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

int check_line_chars(char **line)
{
	int		i;
	char	c;

	i = 0;
	while ((c = (*line)[i]))
	{
		if (ft_isalpha(c))
			c = ft_toupper(c);
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
	new_line = malloc(sizeof(char *) * (m->cols));
	if (!new_line)
		return (NULL);
	while (i < m->cols)
	{
		new_line[i] = write_data(line);
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	set_file_data(char **args, t_map	*m)
{
	char	*line;
	char	***data;
	int		i;

	data = malloc(sizeof(char **) * (m->rows));
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
			data[i] = write_line(&line, m);
			i++;
		}
		line = get_next_line(m->file_desc);
	}
	free(line);
	data[i] = '\0';
	m->file_data = data;
}

void	compute_x(t_map *m, t_point *p, int initial_x)
{
	p->x = initial_x;//x + m->size_x / 2;
}

void	compute_y(t_map *m, t_point *p, int initial_y)
{
	p->y = initial_y;
}

void	add_color_channels(t_point **point, char *color_data)
{
	int	r;
	int	g;
	int	b;
	int	color;

	if (point == NULL) return;
	if (color_data == NULL) return;
	color = ft_atoi_hex(color_data);
	(*point)->color.r = (color >> 16) & 0xFF;
	(*point)->color.g = (color >> 8) & 0xFF;
	(*point)->color.b = color & 0xFF;
}

void	add_point(t_map *m, int y, int x)
{
	char	*data;
	char	*tmp;
	char	*color;
	t_point	*point;
	int		sep;
	int		z;

	sep = 0;
	data = m->file_data[y][x];
	point = malloc(sizeof(t_point));
	if (ft_strchr(data, ','))
	{
		sep = ft_strchr(data, ',') - data;
		if (data + sep + 1)	add_color_channels(&point, data + sep + 1);
	}
	else add_color_channels(&point, "0x00FF04");
	point->z = (int) ft_atoi(ft_split(data, ',')[0]);
	point->x = x;
	point->y = y;
	m->map[y][x] = point;
}

void	normalize_point(t_map *m, int x, int y)
{
	t_point	*p;
	float	x_new;
	float	y_new;
	float	z_scale;

	p = m->map[y][x];
	x_new = (float)x / (float)m->cols;
	y_new = (float)y / (float)m->rows;
	p->sx = (x_new * (m->size_x) * 0.30) + m->size_x / 2;
	p->sy = y_new * (m->size_y) * 0.50;
	p->sz = p->z;
}

void	set_point_data(t_map *m)
{
	int		y;
	int		x;
	t_point **map;

	y = 0;
	x = 0;
	m->map = malloc(sizeof(t_point *) * (m->rows));
	if (!map)
		return ;
	while (m->file_data[y] != NULL)
	{
		x = 0;
		m->map[y] = malloc(sizeof(t_point) * (m->cols));
		while(m->file_data[y][x])
		{
			add_point(m, y, x);
			normalize_point(m, x, y);
			isometric(m, m->map[y][x], 0.5);
			x++;
		}
		y++;
	}
}

void	set_image(t_map *m)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->image = mlx_new_image(m->mlx, m->size_x, m->size_y);
	data->addr = mlx_get_data_addr(data->image, &data->bit_per_pix, &data->len,
									&data->endian);
	m->img = data;
}
void	check_map(t_map *m)
{
	int	set_dims;

	set_dims = set_rows_cols(m);
	if (set_dims == -1) m->status = INVALID;
	if (m->cols == 0 && m->rows == 0) m->status = EMPTY;
	else m->status = CORRECT;
}

t_map	*init_map(int argn, char **args)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	if (!m)
		return (NULL);
	m->file_path = args[1];
	m->file_desc = open(args[1], O_RDONLY);
	m->title = ft_strtrim(args[1], ".fdf");
	check_map(m);
	if (m->status == EMPTY || m->status == INVALID)
		exit(EXIT_FAILURE);
	m->size_x = 1920;
	m->size_y = 1080;
	m->scale_x = m->size_x / m->cols;
	m->scale_y = m->size_y / m->rows;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->size_x, m->size_y, m->title);
	set_file_data(args, m);
	set_image(m);
	set_point_data(m);
	return (m);
}

int	main(int argn, char **args)
{
	t_map	*m;

	check_args(argn, args);
	m = init_map(argn, args);
	if (!m)
	{
		ft_printf("Failed to allocate map\n");
		return (1);
	}
	draw_map(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img->image, 0, 0);
	register_hooks(m);
	mlx_loop(m->mlx);
	//clean_program(m);
	return (0);
}