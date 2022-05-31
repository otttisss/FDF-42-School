/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:37:22 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/20 04:13:01 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "errors_ter.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = find_max(map->z_min, map->z_max);
	map->z_max = find_min(map->z_min, map->z_max);
	map->z_range = 0;
	return (map);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!fdf)
		terminate(ERR_FDF_INIT);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!fdf->win)
		terminate(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		terminate(ERR_FDF_INIT);
	fdf->data = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse));
	return (fdf);
}

t_camera	*cam_init(t_fdf *fdf)
{
	t_camera	*cam;

	cam = (t_camera *)ft_memalloc(sizeof(t_camera));
	if (!cam)
		terminate(ERR_CAMERA_INIT);
	cam->zoom = find_min((WIDTH - MENU_WIDTH) / fdf->map->width / 2,
			HEIGHT / fdf->map->height / 2);
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_divisor = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	return (cam);
}
