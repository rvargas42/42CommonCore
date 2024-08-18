/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:37:02 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/18 15:09:10 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_llist
{
	char			*buffer;
	struct s_llist	*next;
}					t_llist;

char	*get_next_line(int fd);
char	*extract_line(t_llist *llist);
void	copy_line(t_llist *llist, char *line);
void	prepare_next(t_llist **llist);
void	free_llist(t_llist **llist, t_llist *start_node, char *buffer);
int		line_length(t_llist *llist);
void	make_llist(t_llist **llist, int fd);
int		is_new_line(t_llist *llist);
void	add_node(t_llist **llist, char *buffer);
t_llist	*find_last_node(t_llist *llist);

#endif