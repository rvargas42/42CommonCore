/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:28 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 14:29:30 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_minitalk	*create_server(void)
{
	t_minitalk	*server;

	server = malloc(sizeof(t_minitalk));
	if (!server)
		return (NULL);
	server->server_pid = 0;
	server->client_pid = 0;
	return (server);
}

void	server_recieve(int boolean)
{
	static int	bit_displacement = 0;
	static char	letter = 0;
	
	letter += ((boolean & 1) << bit_displacement++);
	if (bit_displacement == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		bit_displacement = 0;
		letter = 0;
	}
	return ;
}

void	server_loop(t_minitalk *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_recieve) == SIG_ERR)
			|| (signal(SIGUSR2, server_recieve) == SIG_ERR))
		{
			ft_putstr("ERROR!, Signal error x_x!\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return ;
}


int	main(int argn, char **argv)
{
	t_minitalk	*talk;
	
	(void) argv;
	talk = NULL;
	if (argn != 1)
	{
		ft_putstr("ERROR!, Use \"./server\" with 1 argument please :)\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = create_server();
		talk->server_pid = getpid();
		ft_putstr("SUCCESS!, Server is ready :D! The PID: ");
		ft_putnbr(talk->server_pid);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}