/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:26 by ravargas          #+#    #+#             */
/*   Updated: 2024/10/03 11:43:43 by ravargas         ###   ########.fr       */
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
	int		sx;
	int		sy;
	int		sz;
	int		isox;
	int		isoy;
	int		z;
	int		x;
	int		y;
	char	*color;
}			t_point;

typedef struct s_line
{
	t_point	p_start;
	t_point	p_end;
}			t_line;


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
	int			min_x;
	int			min_y;
	int			max_x;
	int			max_y;
	t_data		*img;
	int			rows;
	int			cols;
	int			scale_x;
	int			scale_y;
	int			pix_x;
	int			pix_y;
	t_point		***map;
}				t_map;

void	set_rows_cols(t_map *map);
void	throw_error(int code, const char *message);
void 	draw_line(t_map *m, int x0, int y0, int x1, int y1);
void	pixel_to_image(t_data *img, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	isometric(t_map *m, t_point *p, double deg);
void	draw_map(t_map *m);
void	digital_diff(t_map *m, t_point *p1, t_point *p2);

#endif