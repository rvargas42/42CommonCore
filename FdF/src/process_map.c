/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:33:03 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/14 18:44:04 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_line_chars(char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = ft_toupper(line[i]);
		if (!ft_strchr((char const *) ALLOWED, c))
		{
			printf("exited for char : %c \n", c);
			return (-1);
		}
		i++;
	}
	return (0);
}

char	*write_data(char **cursor)
{
	char	*slot;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (**cursor == ' ')
		(*cursor)++;
	while ((*cursor)[len] && (*cursor)[len] != ' ')
		len++;
	slot = malloc(sizeof(char) * (len + 1));
	if (!slot)
		return (NULL);
	while (i < len)
	{
		slot[i] = (*cursor)[i];
		i++;
	}
	slot[i] = '\0';
	*cursor += len;
	return (slot);
}

char	**write_line(char *line, t_map *m)
{
	char	**new_line;
	char	*cursor;
	int		i;

	cursor = line;
	i = 0;
	new_line = malloc(sizeof(char *) * (m->cols + 1));
	if (!new_line)
		return (NULL);
	while (i < m->cols)
	{
		new_line[i] = write_data(&cursor);
		i++;
	}
	new_line[i] = NULL;
	return (new_line);
}

void	set_file_data(char **args, t_map *m)
{
	char	*line;
	char	***data;
	int		i;

	data = malloc(sizeof(char **) * (m->rows + 1));
	i = 0;
	if (!data || m->file_desc == -1)
		exit_program_w_error(m, EBADF);
	line = get_next_line(m->file_desc);
	while (line)
	{
		if (check_line_chars(line) == -1)
			exit_program_w_error(m, EINVAL);
		data[i] = write_line(line, m);
		i++;
		free(line);
		line = get_next_line(m->file_desc);
	}
	data[i] = NULL;
	m->file_data = data;
}
