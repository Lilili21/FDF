#include "fdf.h"

void	draw_all_x(t_map *map)
{
	int i;
	int turn;

	i = 0;
	turn = 0;
	while (i < map->count_strings)
	{
		while (turn < map->line[i] - 1)
		{
			map->x1 = map->start_x + (turn - i) * map->linesizex;
			map->y1 = map->start_y + (turn + i) * map->linesizey
			          - (map->tab[i][turn] * map->z);
			map->x2 = map->start_x + ((turn + 1) - i) * map->linesizex;
			map->y2 = map->start_y + ((turn + 1) + i) * map->linesizey
			          - (map->tab[i][turn + 1] * map->z);
			pixels(map);
			turn++;
		}
		i++;
		turn = 0;
	}
}

void	draw_all_y(t_map *map)
{
	int i;
	int turn;

	i = 0;
	turn = 0;
	while (i < map->count_strings - 1)
	{
		while (turn < map->line[i])
		{
			map->x1 = map->start_x + (turn - i) * map->linesizex;
			map->y1 = map->start_y + (turn + i) * map->linesizey
			          - (map->tab[i][turn] * map->z);
			map->x2 = map->start_x + ((turn) - (i + 1)) * map->linesizex;
			map->y2 = map->start_y + ((turn) + (i + 1)) * map->linesizey
			          - (map->tab[i + 1][turn] * map->z);
			pixels(map);
			turn++;
		}
		i++;
		turn = 0;
	}
}

void	draw(t_map *map)
{
	int i;

	i = 0;
	map->img = mlx_new_image(map->mlx, 1000, 1200);
	map->data = mlx_get_data_addr(map->img, &map->bp, &map->size, &map->endian);
	mlx_string_put(map->mlx, map->win, 50, 50, 0x00FFFFFF, "+/- change level" );
	mlx_string_put(map->mlx, map->win, 50, 70, 0x00FFFFFF, "<-||-> change position" );
	mlx_string_put(map->mlx, map->win, 50, 90, 0x00FFFFFF, "Up/Down change size" );
	while (i < 1000 * 1200)
	{
		map->data[i] = 0x0000FF00;
		i++;
	}
//	draw_all_x(map);
//	draw_all_y(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 120);
}

unsigned long get_color(t_map *map, int i)
{
	return (0x00FFFFFF);
	//if (map->x1 > map->start_x)
	//	return(map->color[i] >> 16);
	//return (map->color[i] >> 8);


}