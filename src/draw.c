#include "fdf.h"
#include <stdio.h>

void	draw_all_x(t_str *str, t_map *map)
{
	int i;

	i = 0;
	while(i < str->count_elems - 1)
	{
		if ((i + 1) % str->length == 0)
			i++;
		pixels(str, map, i, i + 1);
		i++;
	}
}

void	draw_all_y(t_str *str, t_map *map)
{
	int i;

	i = 0;
	printf("alfa = %f, betta = %f, gamma =%f\n", alfa, beta, gamma);
	printf("cos_alfa = %f, cos_betta = %f, cos_gamma =%f\n", cos(alfa), cos(beta), cos(gamma));
	printf("sin_alfa = %f, sin_betta = %f, sin_gamma =%f\n", sin(alfa), sin(beta), sin(gamma));
	while(i < str->count_elems - str->length)
	{
		pixels(str, map, i, i + str->length);
		i++;
	}

}

void	draw(t_str *str, t_map *map)
{
	mlx_string_put(map->mlx, map->win, 50, 50, 0x00FFFFFF, "+/- change level" );
	mlx_string_put(map->mlx, map->win, 50, 70, 0x00FFFFFF, "<-||-> change position" );
	mlx_string_put(map->mlx, map->win, 50, 90, 0x00FFFFFF, "Up/Down change size" );

	map->img = mlx_new_image(map->mlx, map->width - 50, map->height - 130);
	map->data = (int *)mlx_get_data_addr(map->img, &(map->trash), &(map->trash), &(map->trash));

	draw_all_x(str, map);
	draw_all_y(str, map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 50 , 130);
}

unsigned long get_color(t_str *map, int i)
{
	return (0x00FFFFFF);
	//if (map->x1 > map->start_x)
	//	return(map->color[i] >> 16);
	//return (map->color[i] >> 8);

}