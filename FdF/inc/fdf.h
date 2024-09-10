/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:26 by ravargas          #+#    #+#             */
/*   Updated: 2024/09/09 11:02:49 by ravargas         ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;
	int		isox;
	int		isoy;
	char	*color;
}			t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pix;
	int		len;
	int		endian;
}			t_data;

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
	t_data		*img;
	int			rows;
	int			cols;
	float		scale_x;
	float		scale_y;
	double_t	zoom;
	t_point		***map;
}				t_map;

void	set_rows_cols(t_map *map);
void	throw_error(int code, const char *message);
void	bresenham_draw(t_map *m, float x1, float y1, float x2, float y2);
void	pixel_to_image(t_data *img, float x, float y, int color);
void	draw_map(t_map *m);

#endif