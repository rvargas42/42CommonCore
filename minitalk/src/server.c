/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:28 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/25 11:03:53 by ravargas         ###   ########.fr       */
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

void	receive_handler(int sig, siginfo_t *info, void *context)
{
	static int	bits;
	static char	content;

	bits++;
	content |= (sig == SIGUSR1);
	(void)context;
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
	kill(info->si_pid, SIGUSR1);
}

void	init_handlers(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = &receive_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(int argn, char **argv)
{
	t_minitalk			*server;
	struct sigaction	*sa;

	server = NULL;
	if (argn != 1)
		exit(EXIT_FAILURE);
	else
	{
		server = create_server();
		printf("server PID: %d\n", server->server_pid);
		init_handlers();
		while (1)
			pause();
	}
	free(server);
	return (EXIT_SUCCESS);
}