/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:32 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/17 11:53:05 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_minitalk	*create_client()
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
	char	temp;

	i = 8;
	temp = c;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(client->server_pid, SIGUSR1);
		else
			kill(client->server_pid, SIGUSR2);
	}
}

void	send_message(t_minitalk *client, char *message)
{
	int		i;
	char	c;

	while (message[i])
		send_signal(client, message[i++]);
	return ;
}

int	main(int argn, char **argv)
{
	t_minitalk	*client;
	int			server_pid;

	if (argn != 3)
	{
		printf("Incorrect Arguments, should be: pid and message");
		exit(EXIT_FAILURE);
	}
	else
	{
		client = create_client();
		client->server_pid = atoi(argv[1]);
		send_message(client, argv[1]);
	}
	return (1);
}