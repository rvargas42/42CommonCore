/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:33:03 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 16:44:38 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
				return (-1);
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
        if (check_line_chars(&line) == -1)
            exit_program_w_error(m, EINVAL);
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
