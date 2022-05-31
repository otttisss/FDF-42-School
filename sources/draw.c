/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:11:34 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/19 04:32:59 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "color.h"

static void	draw_linex(t_coord a, t_coord b, t_fdf *fdf)
{
	int		x;
	int		y;
	int		dif;
	double	m;
	double	perc;

	dif = 1;
	if (a.x > b.x)
		dif = -1;
	x = 0;
	m = (double)(b.y - a.y) / (b.x - a.x);
	perc = (double)1 / ft_abs(b.x - a.x);
	while (ft_abs(x) < ft_abs(b.x - a.x))
	{
		y = (int)(m * x) + a.y;
		my_put_pixel(fdf, x + a.x, y, get_color(a.color, b.color,
				(double)perc * ft_abs(x)));
		x += dif;
	}
}

static void	draw_liney(t_coord a, t_coord b, t_fdf *fdf)
{
	int		x;
	int		y;
	int		dif;
	double	m;
	double	perc;

	dif = 1;
	if (a.y > b.y)
		dif = -1;
	y = 0;
	m = (double)(b.x - a.x) / (b.y - a.y);
	perc = (double) 1 / ft_abs(b.y - a.y);
	while (ft_abs(y) < ft_abs(b.y - a.y))
	{
		x = (int)(m * y) + a.x;
		my_put_pixel(fdf, x, y + a.y, get_color(a.color, b.color,
				(double) perc * ft_abs(y)));
		y += dif;
	}
}

static void	putlines(t_coord a, t_coord b, t_fdf *fdf)
{
	int	xdif;
	int	ydif;

	if ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0)
		|| (a.x > WIDTH && b.x > WIDTH)
		|| (a.y > HEIGHT && b.y > HEIGHT))
		return ;
	xdif = ft_abs(b.x - a.x);
	ydif = ft_abs(b.y - a.y);
	if (xdif && xdif > ydif)
		draw_linex(a, b, fdf);
	else if (ydif)
		draw_liney(a, b, fdf);
}

static void	draw_back(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_back(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				putlines(project_isometric(new_point(x, y, map), fdf),
					project_isometric(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				putlines(project_isometric(new_point(x, y, map), fdf),
					project_isometric(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	menu_show(fdf);
}
