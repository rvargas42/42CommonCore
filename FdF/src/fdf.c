/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:33 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:01:08 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	valid_file(char **args)
{
	if (strncmp(".fdf", &args[1][strlen(args[1]) - 4], 5) != 0)
		return (0);
	return (1);
}

static void	check_args(int argn, char **args)
{
	if (argn != 2)
		throw_error(22, "Program should receive 1 file.fdf");
	if (!valid_file(args))
		throw_error(22, "File should be .fdf extension type");
}

void	check_map(t_map *m)
{
	int	set_dims;

	set_dims = set_rows_cols(m);
	if (set_dims == -1)
		exit_program_w_error(m, EINVAL);
	if (m->cols == 0 && m->rows == 0)
		exit_program_w_error(m, ENODATA);
	else
		m->status = CORRECT;
}

int	main(int argn, char **args)
{
	t_map	*m;

	check_args(argn, args);
	m = init_map(argn, args);
	if (!m)
	{
		ft_printf("Failed to allocate map\n");
		return (1);
	}
	normalize_and_project(m);
	draw_map(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img->image, 0, 0);
	register_hooks(m);
	mlx_loop(m->mlx);
	clean_program(m);
	return (0);
}
