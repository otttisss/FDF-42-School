/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:58:58 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/16 20:37:12 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int	get_defcolor(int z, t_map *map)
{
	double	per;

	per = percent(map->z_min, map->z_max, z);
	if (per < 0.2)
		return (COLOR_1);
	else if (per < 0.4)
		return (COLOR_2);
	else if (per < 0.6)
		return (COLOR_3);
	else if (per < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}

int	get_light(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int	get_color(int c1, int c2, double p)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (c1 == c2)
		return (c1);
	red = get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	green = get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	blue = get_light(c1 & 0xFF, c2 & 0xFF, p);
	return (red << 16 | green << 8 | blue);
}
