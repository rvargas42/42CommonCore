/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:26 by ravargas          #+#    #+#             */
/*   Updated: 2024/08/28 10:33:08 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "ft_printf/inc/ft_printf.h"
# include "libft/inc/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_map
{
	const char	*file_path;
	int			file_desc;
	char		***file_data;
	void		*mlx;
	void		*window;
	char		*title;
	int			size_x;
	int			size_y;
	void		*img;
	int			rows;
	int			cols;
	t_point		***map;
}			t_map;

void	set_matrix(t_map *map);
void	set_rows_cols(t_map *map);
void	throw_error(int code, const char *message);

#endif