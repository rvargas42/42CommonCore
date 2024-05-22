/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42Madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:37:02 by ravargas          #+#    #+#             */
/*   Updated: 2024/01/30 10:36:27 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <io.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*extract_line(t_list *llist);
void	copy_line(t_list *llist, char *line);
void	prepare_next(t_list **llist);
void	free_llist(t_list **llist, t_list *start_node, char *buffer);
int		line_length(t_list *llist);
void	make_llist(t_list **llist, int fd);
int		is_new_line(t_list *llist);
void	add_node(t_list **llist, char *buffer);
t_list	*find_last_node(t_list *llist);

#endif