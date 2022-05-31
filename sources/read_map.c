/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:08:55 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/23 05:20:10 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "errors_ter.h"
#include <stdlib.h>
#include "get_next_line.h"

static void	free_str_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_pos	*new_coord(char *file_name)
{
	t_pos	*coord;
	char	**line;

	coord = (t_pos *)ft_memalloc(sizeof(t_pos));
	line = ft_split(file_name, ',');
	if (!coord)
		terminate(ERR_MAP_READING);
	if (!line)
		terminate(ERR_MAP_READING);
	if (!ft_isnumber(line[0], 10))
		terminate(ERR_MAP_READING);
	if (line[1] && !ft_isnumber(line[1], 16))
		terminate(ERR_MAP_READING);
	coord->z = ft_atoi(line[0]);
	if (line[1])
		coord->color = ft_atoi_hex(line[1], 16);
	else
		coord->color = -1;
	coord->next = NULL;
	free_str_arr(line);
	return (coord);
}

static void	parse_line(char **coord_line, t_pos **coords_stack,
						t_map *map)
{
	int	width;

	width = 0;
	while (*coord_line)
	{
		push(coords_stack, new_coord(*(coord_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		terminate(ERR_MAP);
}

void	read_map(const int fd, t_pos **coords_stack, t_map *map)
{
	char	*line;
	char	**coord_line;

	while (get_next_line(fd, &line))
	{
		coord_line = ft_split(line, ' ');
		if (!coord_line)
			terminate(ERR_MAP_READING);
		parse_line(coord_line, coords_stack, map);
		free_str_arr(coord_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coords_stack))
		terminate(ERR_MAP);
}
// int					read_map(const int fd,
// 							t_pos **coords_stack,
// 							t_map *map)
// {
// 	char	*line;
// 	int		result;
// 	char	**coords_line;

// 	while ((result = get_next_line(fd, &line)) == 1)
// 	{
// 		if (!(coords_line = ft_split(line, ' ')))
// 			terminate(ERR_MAP_READING);
// 		parse_line(coords_line, coords_stack, map);
// 		free_str_arr(coords_line);
// 		ft_strdel(&line);
// 		map->height++;
// 	}
// 	if (!(*coords_stack))
// 		terminate(ERR_MAP);
// 	return (result);
// }
