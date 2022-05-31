/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:48 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/20 04:16:44 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rot_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

static void	rot_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

static void	rot_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

static void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5);
	*y = -z + (prev_x + prev_y) * sin(0.5);
}

t_coord	project_isometric(t_coord coor, t_fdf *fdf)
{
	coor.x *= fdf->camera->zoom;
	coor.y *= fdf->camera->zoom;
	coor.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	coor.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	coor.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rot_x(&coor.y, &coor.z, fdf->camera->alpha);
	rot_y(&coor.x, &coor.z, fdf->camera->beta);
	rot_z(&coor.x, &coor.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		isometric(&coor.x, &coor.y, coor.z);
	coor.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
	coor.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->y_offset;
	return (coor);
}
