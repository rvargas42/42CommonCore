/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:36:21 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/28 09:11:05 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_llist	*find_last_node(t_llist *llist)
{
	if (!llist)
		return (NULL);
	while (llist->next)
		llist = llist->next;
	return (llist);
}

void	add_node(t_llist **llist, char *buffer)
{
	t_llist	*last_node;
	t_llist	*new_node;

	last_node = find_last_node(*llist);
	new_node = malloc(sizeof(t_llist));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*llist = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buffer;
	new_node->next = NULL;
}

int	is_new_line(t_llist *llist)
{
	int		i;
	char	c;

	while (llist)
	{
		i = 0;
		while (llist->buffer[i] && i < BUFFER_SIZE)
		{
			c = llist->buffer[i];
			if (c == '\n')
				return (1);
			++i;
		}
		llist = llist->next;
	}
	return (0);
}

void	make_llist(t_llist **llist, int fd)
{
	char	*buffer;
	int		bytes;
	t_llist	*prev;

	while (!is_new_line(*llist))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
		{
			while (*llist)
			{
				prev = (*llist)->next;
				free((*llist)->buffer);
				free((*llist));
				*llist = prev;
			}
			free(buffer);
			return ;
		}
		buffer[bytes] = '\0';
		add_node(llist, buffer);
	}
}

int	line_length(t_llist *llist)
{
	int	i;
	int	j;

	i = 0;
	if (llist == NULL)
		return (0);
	while (llist)
	{
		j = 0;
		while (llist->buffer[j])
		{
			if (llist->buffer[j] == '\n')
			{
				++i;
				return (i);
			}
			++i;
			++j;
		}
		llist = llist->next;
	}
	return (i);
}
