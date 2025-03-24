/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:09:13 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/18 14:31:51 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	throw_error(int code, const char *message)
{
	errno = code;
	perror(message);
	exit(EXIT_FAILURE);
}

//free all data from the map and exit the program no error
void	exit_program_wo_error(t_map **map)
{
	return ;
}

void	exit_program_w_error(t_map **map)
{
	return ;
}

void	throw_exit_error(int code, const char *message)
{
	errno = code;
	perror(message);
	exit(EXIT_FAILURE);
}