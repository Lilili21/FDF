/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:55:19 by swarner           #+#    #+#             */
/*   Updated: 2019/05/14 15:45:21 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

t_str	init_str(t_str *str, t_map *map)
{
	map->width = 1200;
	map->height = 1200;
	str->prm.start_x = 200;
	str->prm.start_y = 200;
	str->prm.linesizex = 16;
	str->prm.linesizey = 16;
	str->prm.zoom = 50;
	return (*str);
}

void	ft_str(t_str *str, t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width, map->height, "FdF");
	draw(str, map, 0);
	mlx_mouse_hook(map->win, mouse_pressed, str);
	mlx_key_hook(map->win, key_pressed, str);
	mlx_hook(map->win, 17, 0, &ft_close, NULL);
	mlx_loop(map->mlx);
}

int		main(int argc, char **argv)
{
	t_str		str;
	t_map		map;
	int			fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	if (ft_count(fd, &str) == -1)
		return (-1);
	close(fd);
	init_str(&str, &map);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	work_coords(fd, &str);
	close(fd);
	ft_str(&str, &map);
	printf("str->count_elems = %i, str->count_strings = %i", str.count_elems, str.count_strings);
	return (0);
}
