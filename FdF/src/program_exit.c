/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:09:13 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:13:03 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	throw_error(int code, const char *message)
{
	errno = code;
	perror(message);
	exit(EXIT_FAILURE);
}

void	exit_program_wo_error(t_map *map)
{
	clean_program(map);
	exit(EXIT_SUCCESS);
}

void	exit_program_w_error(t_map *map, int code)
{
	errno = ENODATA;
	perror(strerror(code));
	clean_program(map);
	exit(EXIT_FAILURE);
}
