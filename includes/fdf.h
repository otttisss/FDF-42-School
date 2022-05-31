/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:14:41 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/23 05:20:19 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <string.h>
# include <math.h>
# include <limits.h>

# define HEIGHT	1050
# define WIDTH	1680
# define MENU_WIDTH 250

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum s_iso
{
	ISO,
	PARALLEL
}	t_iso;

typedef struct s_pos
{
	int				z;
	int				color;
	struct s_pos	*next;
}	t_pos;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coord;

typedef struct s_camera
{
	t_iso	projection;
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_divisor;
	int		x_offset;
	int		y_offset;
}	t_camera;

typedef struct s_map
{
	int	width;
	int	height;
	int	*coords_arr;
	int	*colors_arr;
	int	z_min;
	int	z_max;
	int	z_range;
}	t_map;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}	t_fdf;

t_bool		ft_isnumber(char *str, int base);
void		read_map(const int fd, t_pos **coords_stack, t_map *map);
t_map		*map_init(void);
t_fdf		*fdf_init(t_map *map);
void		terminate(char *s);
int			ft_atoi_hex(const char *str, int base);
void		push(t_pos **coords_stack, t_pos *new);
t_pos		*get_elem(t_pos **coords_stack);
double		percent(int start, int end, int current);
t_coord		new_point(int x, int y, t_map *map);
int			get_color(int c1, int c2, double p);
int			get_defcolor(int z, t_map *map);
int			ft_abs(int n);
int			find_max(int a, int b);
int			find_min(int a, int b);
t_coord		project_isometric(t_coord coor, t_fdf *fdf);
t_camera	*cam_init(t_fdf *fdf);
void		my_put_pixel(t_fdf *fdf, int x, int y, int color);
void		stack_to_arr(t_pos **coords_stack, t_map *map);
void		draw(t_map *map, t_fdf *fdf);
void		zoom(int key, t_fdf *fdf);
void		move(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		flatten(int key, t_fdf *fdf);
void		iso_parallel(int key, t_fdf *fdf);
int			keyboard(int key, void *param);
int			mouse_press(int button, int x, int y, void *param);
int			mouse_release(int button, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
int			close_win(void *param);
void		connect_controls(t_fdf *fdf);
void		menu_show(t_fdf *fdf);

#endif