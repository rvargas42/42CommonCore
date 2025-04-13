/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:36:44 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:16:16 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_llist(t_llist **llist, t_llist *start_node, char *buffer)
{
	t_llist	*prev;

	if (llist == NULL)
		return ;
	while (*llist)
	{
		prev = (*llist)->next;
		free((*llist)->buffer);
		free(*llist);
		*llist = prev;
	}
	*llist = NULL;
	if (start_node->buffer[0])
		*llist = start_node;
	else
	{
		free(buffer);
		free(start_node);
	}
}

void	prepare_next(t_llist **llist)
{
	t_llist	*last_node;
	t_llist	*start_node;
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_node = find_last_node(*llist);
	start_node = malloc(sizeof(t_llist));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || !start_node)
		return ;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		++i;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buffer[j++] = last_node->buffer[i];
	buffer[j] = '\0';
	start_node->buffer = buffer;
	start_node->next = NULL;
	free_llist(llist, start_node, buffer);
}

void	copy_line(t_llist *llist, char *line) // está bien
{
	int	i;
	int	j;

	if (llist == NULL || line == NULL)
		return ;
	i = 0;
	while (llist)
	{
		j = 0;
		while (llist->buffer[j])
		{
			if (llist->buffer[j] == '\n')
			{
				line[i++] = '\n';
				line[i] = '\0';
				return ;
			}
			line[i++] = llist->buffer[j++];
		}
		llist = llist->next;
	}
	line[i] = '\0';
}

char	*extract_line(t_llist *llist)
{
	char	*line;
	int		line_len;

	if (llist == NULL)
		return (NULL);
	line_len = line_length(llist);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	copy_line(llist, line);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_llist	*llist = NULL;
	t_llist			*prev;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (llist)
		{
			prev = llist->next;
			free(llist->buffer);
			free(llist);
			llist = prev;
		}
		return (NULL);
	}
	make_llist(&llist, fd);
	if (llist == NULL)
		return (NULL);
	line = extract_line(llist);
	prepare_next(&llist);
	return (line);
}
