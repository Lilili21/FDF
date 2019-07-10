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

void		draw_v(t_str *str, int x, int y, int color)
{
	long int	cur_i;

	cur_i = x + y * (str->map.width_img);
	if (x < str->map.width_img && y < str->map.height_img && x >0 && y > 0
	&& cur_i >= 0 && cur_i < (str->map.width_img) * (str->map.height_img))
		str->map.data[cur_i] = color;
}

void	horizontal(t_str *str, int k)
{
	int err;
	int i;

	i = 0;
	err = str->prm.dx / 2;
	while (i < str->prm.dx)
	{
		str->xyz_tmp[k].x += str->prm.incrx;
		err += str->prm.dy;
		if (err > str->prm.dx)
		{
			err -= str->prm.dx;
			str->xyz_tmp[k].y += str->prm.incry;
		}
		if (k == str->count_elems / 2)
			draw_v(str, str->xyz_tmp[k].x, str->xyz_tmp[k].y, 0x0000FF);
		else
			draw_v(str, str->xyz_tmp[k].x, str->xyz_tmp[k].y, 0xFF0000);
		i++;
	}
}

void	incline(t_str *str, int k)
{
	int err;
	int i;

	i = 0;
	err = str->prm.dy / 2;
	while (i < str->prm.dy)
	{
		str->xyz_tmp[k].y += str->prm.incry;
		err += str->prm.dx;
		if (err >= str->prm.dy)
		{
			err -= str->prm.dy;
			str->xyz_tmp[k].x += str->prm.incrx;
		}
		if (k == str->count_elems / 2)
			draw_v(str, str->xyz_tmp[k].x, str->xyz_tmp[k].y, 0x0000FF);
		else
			draw_v(str, str->xyz_tmp[k].x, str->xyz_tmp[k].y, 0xFF0000);
		i++;
	}
}

void	normalize(t_str *str, int i)
{
	str->xyz_tmp[i].x -= str->delta_x;
	str->xyz_tmp[i].y -= str->delta_y;
}

void	pixels(t_str *str, int i, int j) {
	rotate_x(str, i, 0);
	rotate_x(str, j, 0);
	rotate_y(str, i, 1);
	rotate_y(str, j, 1);
	rotate_z(str, i, 1);
	rotate_z(str, j, 1);
	normalize(str, i);
	normalize(str, j);

	str->prm.incrx = (str->xyz_tmp[j].x > str->xyz_tmp[i].x) ? 1 : -1;
	str->prm.incry = (str->xyz_tmp[j].y > str->xyz_tmp[i].y) ? 1 : -1;
	str->prm.dx = abs(str->xyz_tmp[j].x - str->xyz_tmp[i].x);
	str->prm.dy = abs(str->xyz_tmp[j].y - str->xyz_tmp[i].y);
	if (str->prm.dx > str->prm.dy)
		horizontal(str, i);
	else
		incline(str, i);
	//printf("i = %i, j = %i, x1 = %i, y1 = %i, x2 = %i, y2 = %i\n", i, j, str->xyz_tmp[i].x, str->xyz_tmp[i].y, str->xyz_tmp[j].x, str->xyz_tmp[j].y);
	//if (i == str->count_elems / 2)
	//	draw_v(str, str->xyz_tmp[i].x, str->xyz_tmp[i].y, 0x0000FF);
	}



