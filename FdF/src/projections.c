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
	float	clamp_y;

	clamp_y = ((p->sx + p->sy) * sin(deg));
	p->isox = ((p->sx - p->sy) * cos(deg));
	p->isoy = clamp_y - fmin(clamp_y, p->sz);
}

void	rotate_y(t_map *m, t_point *p, double deg)
{
	p->isox = p->isox * cos(deg) + p->isoy * sin(deg);
	p->sz = p->isox * -sin(deg) + p->sz * cos(deg);
}

void	rotate_x(t_map *m, t_point *p, double deg)
{
	p->isoy = p->isoy * cos(deg) + p->isoy * sin(deg);
	p->sz = p->isoy * -sin(deg) + p->sz * cos(deg);
}

void	rotate_z(t_map *m, t_point *p, double deg)
{
	p->isox = p->isox * cos(deg) - p->isoy * sin(deg);
	p->isoy = p->isox * sin(deg) + p->isoy * cos(deg);
}