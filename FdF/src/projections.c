/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:53:53 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/16 12:17:01 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_map *m, t_point *p, double deg)
{
	int	iso_x;
	int	iso_y;

	iso_x = (p->x - p->y) * cos(deg);
    iso_y = (p->x + p->y) * sin(deg) - p->z;
	p->isox = iso_x + (m->size_x / 2);
	p->isoy = iso_y + (m->size_y / 2);
}