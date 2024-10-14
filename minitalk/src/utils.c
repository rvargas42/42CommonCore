/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:24:44 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/27 15:34:26 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while (n > 0)
	{
		ps[i] = '\0';
		i++;
		n--;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_pid(char *pid_str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (pid_str[i])
	{
		c = pid_str[i];
		if (!ft_isdigit(c))
			return (0);
		i++;
	}
	return (1);
}

int	pid_exists(int pid)
{
	int	exists;

	exists = (kill(pid, 0) == 0);
	return (exists);
}
