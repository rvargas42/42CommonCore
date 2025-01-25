/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:23:53 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/18 20:44:32 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_matrix(t_map *map)
{
	t_point ***matrix;

	matrix = (t_point ***)malloc(map->rows * sizeof(t_point **));
	
}