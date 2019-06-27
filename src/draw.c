#include "fdf.h"

void	draw_all_x(t_map *map)
{
	int i;

	i = 0;
	map->turn = 0;
	while (i < map->count_strings)
	{
		while (map->turn < map->line[i] - 1)
		{
			map->x1 = map->view_x + (map->turn - i) * map->linesizex;
			map->y1 = map->view_y + (map->turn + i) * map->linesizey
			          - (map->tab[i][map->turn] * map->z);
			map->x2 = map->view_x + ((map->turn + 1) - i) * map->linesizex;
			map->y2 = map->view_y + ((map->turn + 1) + i) * map->linesizey
			          - (map->tab[i][map->turn + 1] * map->z);
			pixels(map);
			map->turn++;
		}
		i++;
		map->turn = 0;
	}
}

void	draw_all_y(t_map *map)
{
	int i;

	i = 0;
	map->turn = 0;
	while (i < map->count_strings - 1)
	{
		while (map->turn < map->line[i])
		{
			map->x1 = map->view_x + (map->turn - i) * map->linesizex;
			map->y1 = map->view_y + (map->turn + i) * map->linesizey
			          - (map->tab[i][map->turn] * map->z);
			map->x2 = map->view_x + ((map->turn) - (i + 1)) * map->linesizex;
			map->y2 = map->view_y + ((map->turn) + (i + 1)) * map->linesizey
			          - (map->tab[i + 1][map->turn] * map->z);
			pixels(map);
			map->turn++;
		}
		i++;
		map->turn = 0;
	}
}

void	draw(t_map *map)
{
	draw_all_x(map);
	draw_all_y(map);
}