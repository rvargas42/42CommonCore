/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:59:21 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/03 10:00:48 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int delete_image(long int code, t_map *m)
{
	if (code == KEY_ESC)
	{
		mlx_destroy_image(m->mlx, m->img->img);
		return (0);
	}
	return (0);
}

void	register_hooks(t_map *m)
{
	mlx_key_hook(m->window, delete_image, m);
	return ;
}

void	hooks(int code, t_map *m)
{
	return ;
}
