/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:53:53 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/03 12:16:43 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_map *m, t_point *p, double deg)
{
	p->isox = ((p->sx - p->sy) * cos(deg));
	p->isoy = ((p->sx + p->sy) * sin(deg) - p->sz);
}