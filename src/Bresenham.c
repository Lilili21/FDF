#include "fdf.h"

void		draw_v(t_map *map, int x, int y)
{
	int	i;

	i = (int)y * 4 + (int)x * map->start_x;

	map->data[i] = map->color;
	map->data[++i] = map->color >> 8;
	map->data[++i] = map->color >> 16;
}

void	positive(t_map *map)
{
	int err;
	int i;

	i = 0;
	err = map->dx / 2;
	while (i < map->dx)
	{
		map->x1 += map->incrx;
		err += map->dy;
		if (err > map->dx)
		{
			err -= map->dx;
			map->y1 += map->incry;
		}
		//draw_v(map, map->x1, map->y1);
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(map, i));
		i++;
	}
}

void	negative(t_map *map)
{
	int err;
	int i;

	i = 0;
	err = map->dy / 2;
	while (i < map->dy)
	{
		map->y1 += map->incry;
		err += map->dx;
		if (err > map->dy)
		{
			err -= map->dy;
			map->x1 += map->incrx;
		}
		//draw_v(map, map->x1, map->y1);
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(map, i));
		i++;
	}
}

void	pixels(t_map *map)
{
	map->incrx = (map->x2 > map->x1) ? 1 : -1;
	map->incry = (map->y2 > map->y1) ? 1 : -1;
	map->dx = abs(map->x2 - map->x1);
	map->dy = abs(map->y2 - map->y1);
	if (map->dx > map->dy)
	{
		positive(map);
	}
	else
	{
		negative(map);
	}
	//draw_v(map, map->x1, map->y1);
	//draw_v(map, map->x2, map->y2);
	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(map, 0));
	mlx_pixel_put(map->mlx, map->win, map->x2, map->y2, get_color(map, 0));
}
