/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:55:19 by swarner           #+#    #+#             */
/*   Updated: 2019/07/10 15:02:12 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_str	init_str(t_str *str)
{
	str->map.width = 1200;
	str->map.height = 1200;
	str->map.width_img = str->map.width - 50;
	str->map.height_img = str->map.height - 130;
	str->prm.start_x = 0; //center
	str->prm.start_y = 0; //center
	str->prm.linesizex = 16;
	str->prm.linesizey = 16;
	str->prm.zoom = 30;
	str->x_alfa = 0.20;
	str->y_alfa = 0.20;
	str->z_alfa = 0.20;
	return (*str);
}

int		main(int argc, char **argv)
{
	t_str	str;
	int		fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	if (ft_count(fd, &str) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	init_str(&str);
	fd = open(argv[1], O_RDONLY);
	work_coords(fd, &str);
	close(fd);
	str.map.mlx = mlx_init();
	str.map.win = mlx_new_window(str.map.mlx, str.map.width, str.map.height,
			"FdF");
	draw(&str, 0);
	mlx_key_hook(str.map.win, key_pressed, &str);
	mlx_hook(str.map.win, 17, 0, &ft_close, NULL);
	mlx_loop(str.map.mlx);
	return (0);
}

