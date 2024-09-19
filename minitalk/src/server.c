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
	server->server_pid = getpid();;
	server->client_pid = 0;
	return (server);
}

void	receive_handler(int sig)
{
	static int	bits;
	static char	content;

	bits++;
	content |= (sig == SIGUSR1);
	if (bits == 8)
	{
		if (content == '\0')
			write(1, "\n", 1);
		else
			write(1, &content, 1);
		bits = 0;
		content = 0;
	}
	else
		content <<= 1;
}

int	main(int argn, char **argv)
{
	t_minitalk			*server;

	server = NULL;
	if (argn != 1)
		exit(EXIT_FAILURE);
	else
	{
		server = create_server();
		printf("server PID: %d\n", server->server_pid);
		signal(SIGUSR1, receive_handler);
		signal(SIGUSR2, receive_handler);
		while (1)
			pause();
	}
	free(server);
	return (EXIT_SUCCESS);
}