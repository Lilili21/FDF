/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:26:50 by gfoote            #+#    #+#             */
/*   Updated: 2019/06/27 20:27:12 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_close(void *param)
{
	(void)param;
	exit(0);
}

/*
** up, down, right, left, increase z +, decrease z -
*/

int		key_move(int keycode, t_str *str, t_map *map)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78)
	{
		if (keycode == 126)
			str->prm.start_y -= 100;
		else if (keycode == 125)
			str->prm.start_y += 100;
		else if (keycode == 124)
			str->prm.start_x += 100;
		else if (keycode == 123)
			str->prm.start_x -= 100;
		else if (keycode == 69)
			str->prm.zoom +=10;
		else if (keycode == 78)
			str->prm.zoom -= 10;
		mlx_clear_window(map->mlx, map->win);
		draw(str, map);
	}
	return (0);
}

/*
**  Colors
*/
/*
int		key_color(int keycode, t_str *map)
{
	if (keycode == 11)
	{
		map->color -= (0x00FFFFFF - 0x000000FF) / 255;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (keycode == 15)
	{
		map->color -= (0x00FFFFFF - 0x00FF0000) / 255;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (keycode == 5)
	{
		map->color -= (0x00FFFFFF - 0x0000FF00) / 255;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	return (0);
}
*/
/*
**  esc, delete, zoom home, zoom end
*/

int		key_pressed(int keycode, t_str *str, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	else if (keycode == 119 || keycode == 115 || keycode == 51)
	{
		if (keycode == 51)
			init_str(str, map);
		if (keycode == 115)
		{
			str->prm.linesizex *= 2;
			str->prm.linesizey *= 2;
		}
		else if (str->prm.linesizey > 1)
		{
			str->prm.linesizex /= 2;
			str->prm.linesizey /= 2;
		}
		mlx_clear_window(map->mlx, map->win);
		draw(str, map);
	}
	//key_move(keycode, str, map);
	//key_color(keycode, map);
	return (0);
}

/*
int mouse_pressed(int button, t_str *map)
{
	if (button == 4)
	{
		map->linesizex = map->linesizex * 2;
		map->linesizey = map->linesizey * 2;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (button == 5)
	{
		map->linesizex = map->linesizex * 2;
		map->linesizey = map->linesizey * 2;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (button == 3)
	{
		init_str(map);
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (button == 2)
	{
		map->z++;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	if (button == 1)
	{
		map->z--;
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	return (0);
}*/

