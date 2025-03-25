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

int	close_display(long int code, t_map *m)
{
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}

int	mouse_hooks(long int code, t_map *m)
{
	return (0);
}

int	key_hooks(long int code, t_map *m)
{
	if (code == KEY_ESC)
		close_display(code, m);
	return (0);
}

void	register_hooks(t_map *m)
{
	mlx_hook(m->win, DestroyNotify, ButtonPressMask, close_display, m);
	mlx_hook(m->win, 2, 1L<<0, key_hooks, m);

}
