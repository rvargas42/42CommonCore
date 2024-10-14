/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:32 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/27 15:37:27 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	g_ack = 0;

void	ack_handle(int sig)
{
	if (sig)
		g_ack = 1;
}

t_minitalk	*create_client(void)
{
	t_minitalk	*client;

	client = malloc(sizeof(t_minitalk));
	if (!client)
		return (NULL);
	client->client_pid = 0;
	client->server_pid = 0;
	return (client);
}

void	send_signal(t_minitalk *client, char c)
{
	int		i;

	i = 8;
	while (i > 0)
	{
		i--;
		g_ack = 0;
		if (c & (1 << i))
			kill(client->server_pid, SIGUSR1);
		else
			kill(client->server_pid, SIGUSR2);
		usleep(42);
		while (!g_ack)
			pause();
	}
}

void	send_message(t_minitalk *client, char *message)
{
	int		i;

	i = 0;
	while (message[i])
	{
		send_signal(client, message[i]);
		i++;
	}
	send_signal(client, '\0');
}

int	main(int argn, char **argv)
{
	t_minitalk	*client;

	if (argn != 3)
	{
		ft_printf("Incorrect Arguments, should be: server and message");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (check_pid(argv[1]) == 0 || !pid_exists(ft_atoi(argv[1])))
		{
			ft_printf("Check pid, invalid PID or format");
			return (EXIT_FAILURE);
		}
		client = create_client();
		client->server_pid = ft_atoi(argv[1]);
		signal(SIGUSR1, ack_handle);
		send_message(client, argv[2]);
	}
	free(client);
	return (EXIT_SUCCESS);
}
