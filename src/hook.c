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
int		key_move(int keycode, t_str *str)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78 ||
		keycode == 7 || keycode == 8 || keycode == 1 || keycode == 2 ||
		keycode == 13 || keycode == 14)
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
		else if(keycode == 1)
			str->x_alfa += 0.10;
		else if(keycode == 2)
			str->x_alfa -= 0.10;
		else if(keycode == 7)
			str->y_alfa += 0.10;
		else if(keycode == 8)
			str->y_alfa -= 0.10;
		else if(keycode == 13)
			str->z_alfa += 0.10;
		else if(keycode == 14)
			str->z_alfa -= 0.10;
		mlx_clear_window(str->map.mlx, str->map.win);
		if(keycode == 69 || keycode == 78)
			draw(str, 0);
		else
			draw(str, 1);
	}
	return (0);
}

/*
**  esc, delete, zoom home, zoom end
*/
int		key_pressed(int keycode, t_str *str)
{
	int turn;

	turn = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(str->map.mlx, str->map.win);
		exit(0);
	}
	else if (keycode == 119 || keycode == 115 || keycode == 51)
	{
		if (keycode == 51)
			init_str(str);
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
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, turn);
	}
	key_move(keycode, str);
	//key_color(keycode, map);
	return (0);
}
/*
int		mouse_pressed(int button, int x, int y, void *param)
{
	t_str		*str;

	str = (t_str*)param;
	if (button == 4)
	{
	//	map.mlx_destroy_window(map->map.mlx, map->img);

		str->prm.linesizex /= 2;
		str->prm.linesizey /= 2;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 1);
	}
	if (button == 5)
	{
		mlx_clear_window(str->map.mlx, str->map.win);
		//mlx_destroy_window(str->map.mlx, str->map.img);
		str->prm.linesizex *= 2;
		str->prm.linesizey *= 2;
		//
		draw(str, 1);
	}
	if (button == 3)
	{
		init_str(str);
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 0);
	}
	if (button == 2)
	{
		str->prm.zoom++;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 0);
	}
	if (button == 1)
	{
		mlx_clear_window(str->map.mlx, str->map.win);
		mlx_destroy_window(str->map.mlx, str->map.img);
		//free(map->img);
		str->prm.zoom++;
		//map.mlx_clear_window(map->map.mlx, map->win);
		draw(str, 0);
	}
	return (0);
}

*/