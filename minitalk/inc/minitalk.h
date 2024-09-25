/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:52:22 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/24 12:03:21 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H
# define _GNU_SOURCE

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../inc/libft/libft.h"


typedef struct	s_minitalk
{
	int	server_pid;
	int	client_pid;
}		t_minitalk;


#endif