/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:52:22 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 14:32:33 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>


typedef struct	s_minitalk
{
	int	server_pid;
	int	client_pid;
}		t_minitalk;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int num);


#endif