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

int	close_display(void *param)
{
	t_map *m;

	m = (t_map *) param;
	mlx_loop_end(m->mlx);
	return (0);
}

int	mouse_hooks(long int code, t_map *m)
{
	return (0);
}

int	key_hooks(long int code, t_map *m)
{
	if (code == KEY_ESC)
		close_display(m);
	return (0);
}

void	register_hooks(t_map *m)
{
	mlx_hook(m->win, DestroyNotify, ButtonPressMask, close_display, m);
	mlx_hook(m->win, 2, 1L<<0, key_hooks, m);
}
