/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:28 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/01 10:51:30 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_minitalk	*create_server(void)
{
	t_minitalk	*server;

	server = malloc(sizeof(t_minitalk));
	if (!server)
		return (NULL);
	server->server_pid = getpid();
	server->client_pid = 0;
	return (server);
}

void	receive_handler(int sig, siginfo_t *info, void *other)
{
	static t_server_handle	serv_info;	

	(void)other;
	serv_info.bits++;
	serv_info.content |= (sig == SIGUSR1);
	if (serv_info.current_client == 0)
		serv_info.current_client = info->si_pid;
	if (serv_info.bits == 8 && serv_info.current_client == info->si_pid)
	{
		if (serv_info.content == '\0')
			write(1, "\n", 1);
		else
			write(1, &serv_info.content, 1);
		serv_info.bits = 0;
		serv_info.content = 0;
		serv_info.current_client = 0;
		serv_info.receiving = 1;
	}
	else
		serv_info.content <<= 1;
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

	server = NULL;
	if (argn != 1)
	{
		ft_printf("No other args than ./%s are allowed", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		server = create_server();
		ft_printf("server PID: %d\n", server->server_pid);
		init_handlers();
		while (1)
			pause();
	}
	free(server);
	return (EXIT_SUCCESS);
}
