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
		if(keycode == 69 || keycode == 78)
			draw(str, map, 0);
		else
			draw(str, map, 1);
	}
	return (0);
}

/*
**  esc, delete, zoom home, zoom end
*/
int		key_pressed(int keycode, t_str *str, t_map *map)
{
	int turn;

	turn = 0;
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
			turn = 1;
			str->prm.linesizex *= 2;
			str->prm.linesizey *= 2;
		}
		else if (str->prm.linesizey > 1)
		{
			turn = 1;
			str->prm.linesizex /= 2;
			str->prm.linesizey /= 2;
		}
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, turn);
	}
	key_move(keycode, str, map);
	//key_color(keycode, map);
	return (0);
}

int mouse_pressed(int button, t_str *str, t_map *map)
{
	if (button == 4)
	{
		str->prm.linesizex /= 2;
		str->prm.linesizey /= 2;
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, 1);
	}
	if (button == 5)
	{
		str->prm.linesizex *= 2;
		str->prm.linesizey *= 2;
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, 1);
	}
	if (button == 3)
	{
		init_str(str, map);
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, 0);
	}
	if (button == 2)
	{
		str->prm.zoom++;
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, 0);
	}
	if (button == 1)
	{
		str->prm.zoom++;
		mlx_clear_window(map->mlx, map->win);
		draw(str, map, 0);
	}
	return (0);
}

