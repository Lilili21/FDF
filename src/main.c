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

#include "fdf.h"

t_map	init_map(t_map *map)
{
	map->height = 1200;
	map->width = 1200;
	map->color = 0x00FFFFFF;
	map->linesizex = 32;
	map->linesizey = 16;
	map->z = 2;
	map->view_x = 400;
	map->view_y = 400;
	return (*map);
}

void	ft_map(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width, map->height, "FdF");
	draw(map);
	mlx_key_hook(map->win, key_pressed, map);
	mlx_hook(map->win, 17, 0, &ft_close, NULL);
	mlx_loop(map->mlx);
}

int		main(int argc, char **argv)
{
	t_map		map;
	int			fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	init_map(&map);
	ft_str_count(fd, &map);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	work_coords(fd, &map);
	ft_map(&map);
	return (0);
}
