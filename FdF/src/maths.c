/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:02:01 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:06:17 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	euclidean_distance(int x1, int x2, int y1, int y2)
{
	double	y_delta;
	double	x_delta;
	double	distance;

	x_delta = x1 - x2;
	y_delta = y1 - y2;
	distance = sqrt(pow(x_delta, 2) + pow(y_delta, 2));
	return (distance);
}

double	point_weight(int x, int y, t_point *p1, t_point *p2)
{
	double	full_distance;
	double	point_distance;
	double	relative_distance;

	full_distance = euclidean_distance(p1->isox, p2->isox, \
		p1->isoy, p2->isoy);
	point_distance = euclidean_distance(p1->isox, x, p1->isoy, y);
	relative_distance = point_distance / full_distance;
	return (relative_distance);
}
