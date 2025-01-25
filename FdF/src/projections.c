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

int	get_max_z(t_map *m)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i + 1 < m->rows)
	{
		j = 0;
		while (j + 1 < m->cols)
		{
			printf("z");
			// if (m->map[i][j]->sz > max)
			// {
			// 	max = m->map[i][j]->sz;
			// }
			j += 1;
		}
		i += 1;
	}
	return (max);
}

void	scale_z(t_point *p, t_map *m)
{
	int		max_z;
	double	min_z;
	double	scale_factor;
	double	scaled_z;

	max_z = get_max_z(m);
	
	//scale_factor = (double)((double)(p->sz) / get_max_z(m));
	//printf("scale factor :: %f\n", scale_factor);
	// scaled_z = scale_factor * (double)p->sz;
	// printf("scale factor :: %d\n", get_max_z(m));
	// p->sz = scaled_z;
}

void	isometric(t_map *m, t_point *p, double deg)
{
	// p->isox = ((p->sx - p->sy) * cos(deg));
	// p->isoy = ((p->sx + p->sy) * sin(deg) - p->z);
	p->isox = p->sx * cos(0.50) + p->sy * cos(0.5 + 2) + p->sz * cos(0.50 - 2);
	p->isoy = p->sx * sin(0.50) + p->sy * sin(0.5 + 2) + p->sz * sin(0.50 - 2);
	scale_z(p, m);

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