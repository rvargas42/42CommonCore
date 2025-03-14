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

int close_window(int code, t_map *m)
{
	mlx_destroy_window(m->mlx, m->window);
	clean_program(m);
	return (0);
}

void	register_hooks(t_map *m)
{
	mlx_hook(m->window, DestroyNotify, ButtonPressMask, close_window, m);
	return ;
}

void	hooks(int code, t_map *m)
{
	return ;
}
