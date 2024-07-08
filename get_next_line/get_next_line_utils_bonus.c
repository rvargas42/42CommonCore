/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42Madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:36:21 by ravargas          #+#    #+#             */
/*   Updated: 2024/03/14 13:04:27 by fullname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_last_node(t_list *llist)
{
	if (!llist)
		return (NULL);
	while (llist->next)
		llist = llist->next;
	return (llist);
}

void	add_node(t_list **llist, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = find_last_node(*llist);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*llist = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buffer;
	new_node->next = NULL;
}

int	is_new_line(t_list *llist)
{
	int	i;

	while (llist)
	{
		i = 0;
		while (llist->buffer[i] && i < BUFFER_SIZE)
		{
			if (llist->buffer[i] == '\n')
				return (1);
			++i;
		}
		llist = llist->next;
	}
	return (0);
}

void	make_llist(t_list **llist, int fd)
{
	char	*buffer;
	int		bytes;

	while (!is_new_line(*llist))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
		{
			free(buffer);
			return ;
		}
		buffer[bytes] = '\0';
		add_node(llist, buffer);
	}
}

int	line_length(t_list *llist)
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
