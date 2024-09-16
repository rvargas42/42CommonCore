/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:28 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 12:19:04 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


t_minitalk	*create_server(void)
{
	t_minitalk	*server;

	server = malloc(sizeof(t_minitalk));
	if (!server)
		return (NULL);
	server->server_pid = getpid();
	return (server);
}

int	main(void)
{
	t_minitalk	*server;

	server = create_server();
	if (server)
	{
		printf("server activated!\n");
		printf("Server PID: %d\n", getpid());
	}
	else
	{
		printf("ERROR initializing server!\n");
	}
	free(server);
	return (1);
}