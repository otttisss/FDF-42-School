/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:08:15 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/20 04:08:00 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "errors_ter.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_pos	*coords_stack;
	t_fdf	*fdf;

	errno = 0;
	coords_stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd && fd >= 0)
			terminate(ERR_MAP);
		map = map_init();
		read_map(fd, &coords_stack, map);
		fdf = fdf_init(map);
		stack_to_arr(&coords_stack, map);
		fdf->camera = cam_init(fdf);
		draw(fdf->map, fdf);
		connect_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (0);
}
