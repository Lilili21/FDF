/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:17:28 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/05 20:17:40 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		draw_v(t_map *map, int x, int y, int color)
{
	long int	cur_i;

	cur_i = x + y * (map->width);
	if (cur_i >= 0 && cur_i < map->width * map->height)
		map->data[cur_i] = color;
}

void	horizontal(t_str *str, t_map *map)
{
	int err;
	int i;

	i = 0;
	err = str->prm.dx / 2;
	while (i < str->prm.dx)
	{
		str->x1 += str->prm.incrx;
		err += str->prm.dy;
		if (err > str->prm.dx)
		{
			err -= str->prm.dx;
			str->y1 += str->prm.incry;
		}
		draw_v(map, str->x1, str->y1, 0x00FF00);
		i++;
	}
}

void	incline(t_str *str, t_map *map)
{
	int err;
	int i;

	i = 0;
	err = str->prm.dy / 2;
	while (i < str->prm.dy)
	{
		str->y1 += str->prm.incry;
		err += str->prm.dx;
		if (err >= str->prm.dy)
		{
			err -= str->prm.dy;
			str->x1 += str->prm.incrx;
		}
		draw_v(map, str->x1, str->y1, 0x00FFFF);
		i++;
	}
}

void	pixels(t_str *str, t_map *map, int i, int j)
{
	str->x1 = cos(beta)*cos(gamma)*str->xyz[i].x +
				cos(beta)*sin(gamma)*str->xyz[i].y +
				sin(beta)*str->xyz[i].z* str->prm.zoom;
	str->y1 = (-sin(alfa)*sin(beta)*cos(gamma) -
			 	cos(alfa)*sin(gamma)) * str->xyz[i].x +
				(cos(alfa)*cos(gamma) -
				sin(alfa)*sin(beta)*sin(gamma))*str->xyz[i].y +
				sin(alfa)*cos(beta)*str->xyz[i].z * str->prm.zoom;
	str->x2 = cos(beta)*cos(gamma)*str->xyz[j].x +
				cos(beta)*sin(gamma)*str->xyz[j].y +
				sin(beta)*str->xyz[j].z * str->prm.zoom;
	str->y2 = (-sin(alfa)*sin(beta)*cos(gamma) -
				cos(alfa)*sin(gamma)) * str->xyz[j].x +
				(cos(alfa)*cos(gamma) -
				sin(alfa)*sin(beta)*sin(gamma))*str->xyz[j].y +
			  sin(alfa)*cos(beta)*str->xyz[j].z * str->prm.zoom;
	str->prm.incrx = (str->x2 > str->x1) ? 1 : -1;
	str->prm.incry = (str->y2 > str->y1) ? 1 : -1;
	str->prm.dx = abs(str->x2 - str->x1);
	str->prm.dy = abs(str->y2 - str->y1);
	if (str->prm.dx > str->prm.dy)
		horizontal(str, map);
	else
		incline(str, map);

	printf("i = %i, j = %i, x1 = %i, y1 = %i, x2 = %i, y2 = %i\n", i, j, str->x1, str->y1, str->x2, str->y2);
	draw_v(map, str->x1, str->y1, 0xFFFFFF);
	draw_v(map, str->x2, str->y2, 0xFFFFFF);

}
