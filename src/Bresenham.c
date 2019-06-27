#include "fdf.h"

/*
**	Positive case (dx > dy)
*/

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
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, map->color);
		i++;
	}
}

/*
**	Negative case (dx < dy)
*/

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
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, map->color);
		i++;
	}
}

/*
**	Bresenham Algorithm
**	Define values of incr, in order to obtain direction coefficients.
**	Then draw in function of results.
*/

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
	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, map->color);
	mlx_pixel_put(map->mlx, map->win, map->x2, map->y2, map->color);

}