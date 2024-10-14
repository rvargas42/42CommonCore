/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:52:22 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/03 12:48:20 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/inc/ft_printf.h"
# include "libft/inc/libft.h"

typedef struct s_minitalk
	int	server_pid;0
{
	int	client_pid;
}		t_minitalk;

typedef struct s_server_handle
{
	pid_t	current_client;
	int		receiving;
	int		bits;
	char	content;
}			t_server_handle;

void	ft_bzero(void *s, size_t n);
int		check_pid(char *pid_str);
int		pid_exists(int pid);

#endif