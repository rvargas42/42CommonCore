/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:32 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 13:59:06 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_minitalk	*create_client()
{
	t_minitalk	*client;

	client = malloc(sizeof(t_minitalk));
	if (!client)
		return (NULL);
	return (client);
}

int	main(int argn, const char **argv)
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
		client->client_pid = 0;
		client->server_pid = ft_atoi(argv[1]);
	}
	return (1);
}