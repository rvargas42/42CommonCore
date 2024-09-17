/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:28 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/17 11:49:51 by ravargas         ###   ########.fr       */
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

void	receive_handler(int sig)
{
	static char	current;
	static int	bits;

	current |= (sig == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (current == '\0')
			write(1, "\n", 2);
		else
			write(1, &current, 1);
		bits = 0;
		current = 0;
	}
	else
		current <<= 1;
	printf("executing handler\n");
	return ;
}

void	server_receive(t_minitalk *server)
{
	while (1)
	{
		signal(SIGUSR1, receive_handler);
		signal(SIGUSR2, receive_handler);
		sleep(10);
	}
	return ;
}

int	main(int argn, char **argv)
{
	t_minitalk	*server;

	server = NULL;
	if (argn != 1)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		server = create_server();
		server->server_pid = getpid();
		printf("server PID: %d\n", server->server_pid);
		server_receive(server);
	}
	free(server);
	return (EXIT_SUCCESS);
}