/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:32 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 14:31:43 by ravargas         ###   ########.fr       */
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

void	client_send(t_minitalk *talk, char *message)
{
	int	bit_displacement;
	int	i;
	int	signal;

	i = -1;
	while (++i <= ft_strlen(message))
	{
		bit_displacement = -1;
		signal = 0;
		while (++bit_displacement < 7)
		{
			if ((message[i] >> bit_displacement) & 1)
			{
				signal = SIGUSR2;
			}
			else
				signal = SIGUSR1;
			kill(talk->server_pid, signal);
			usleep(200);
		}
	}
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
		client_send(client, argv[1]);
	}
	return (1);
}