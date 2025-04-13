/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:53:26 by ravargas          #+#    #+#             */
/*   Updated: 2025/04/13 17:50:48 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_ESC 65307
# define MOUSE_LEFT 1
# define ALLOWED "0123456789XABCDEF\n ,-+"

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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

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
	t_color	*color;
}			t_point;

typedef struct s_line
{
	t_point	p_start;
	t_point	p_end;
}			t_line;


typedef	struct	s_data
{
	void	*image;
	char	*addr;
	int		bit_per_pix;
	int		len;
	int		endian;
}			t_data;

typedef	enum	e_status {
	CORRECT,
	EMPTY,
	INVALID,
}	t_status;

typedef struct	s_draw {
	t_point	*p1;
	t_point	*p2;
	int		color;
	int		x;
	int		y;
	int		sx;
	int		sy;
	int		err;
	int		dx;
	int		dy;
}			t_draw;

typedef struct s_scales {
	float	scalef;
	float	scalex;
	float	scaley;
	float	scalez;
}		t_scales;

typedef struct s_minmax {
	int	min_x;
	int	min_y;
	int	min_z;
	int	max_x;
	int	max_y;
	int	max_z;
}		t_minmax;

typedef struct s_map
{
	void		*win;
	void		*mlx;
	const char	*file_path;
	int			rows;
	int			cols;
	int			size_x;
	int			size_y;
	int			file_desc;
	char		***file_data;
	char		*title;
	t_status	status;
	t_data		*img;
	t_point		***map;
	t_draw		*line;
	t_minmax	min_max;
	t_scales	scale;
}				t_map;

void	set_file_data(char **args, t_map	*m);
t_map	*init_map(int argn, char **args);
void	normalize_and_project(t_map *m);
void	set_point_data(t_map *m);
void	register_hooks(t_map *m);
void	clean_program(t_map *map);
void	exit_program_wo_error(t_map *map);
void	exit_program_w_error(t_map *map, int code);
void	throw_error(int code, const char *message);
int		set_rows_cols(t_map *map);
void	init_min_max(t_map *m);
void	update_min_max(t_map *m, t_point *p);
void	check_map(t_map *m);
void	isometric(t_map *m, t_point *p, double deg);
void	bresenham(t_map *m, t_point *p1, t_point *p2);
void	draw_line(t_map *m, t_point *p1, t_point *p2);
void	pixel_to_image(t_map *m, t_point *p1, t_point *p2);
int		create_trgb(int t, int r, int g, int b);
void	project_map(t_map *m, double deg);
void	draw_map(t_map *m);
void	set_min_max(t_map *m);
void	rotate_y(t_map *m, t_point *p, double deg);
void	rotate_z(t_map *m, t_point *p, double deg);
void	rotate_x(t_map *m, t_point *p, double deg);
int		ft_atoi_hex(char *num);
void	digital_diff(t_map *m, t_point *p1, t_point *p2);
double	euclidean_distance(int x1, int x2, int y1, int y2);
double	point_weight(int x, int y, t_point *p1, t_point *p2);

#endif