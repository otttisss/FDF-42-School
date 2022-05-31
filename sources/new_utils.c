/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:41:07 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/20 03:48:18 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "errors_ter.h"

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_coord	new_point(int x, int y, t_map *map)
{
	t_coord	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	if (map->colors_arr[index] == -1)
		point.color = get_defcolor(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}

void	stack_to_arr(t_pos **coords_stack, t_map *map)
{
	t_pos	*coord;
	ssize_t	i;
	size_t	arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)ft_memalloc(arr_size);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	i = map->width * map->height - 1;
	while (i >= 0)
	{
		coord = get_elem(coords_stack);
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}
