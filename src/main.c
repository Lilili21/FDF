/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:49:17 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 12:49:35 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_str		init_str(t_str *str)
{
	str->iso = 0;
	str->map.width = 2400;
	str->map.height = 1700;
	str->map.width_img = str->map.width - 50;
	str->map.height_img = str->map.height - 150;
	str->prm.move_y = 0;
	str->prm.move_x = 0;
	str->prm.linesizex = 16;
	str->prm.linesizey = 16;
	while (str->map.width_img < str->prm.linesizex * str->length ||
	str->map.height_img < str->prm.linesizey * str->count_strings)
	{
		str->prm.linesizex /= 2;
		str->prm.linesizey /= 2;
	}
	str->x_center = str->length * str->prm.linesizex / 2;
	str->y_center = str->count_strings * str->prm.linesizey / 2;
	str->prm.zoom = 2;
	str->x_alfa = 0.00;
	str->y_alfa = 0.00;
	str->z_alfa = 0.00;
	return (*str);
}

void		draw_str(t_str str)
{
	str.map.mlx = mlx_init();
	str.map.win = mlx_new_window(str.map.mlx, str.map.width, str.map.height,
			"FdF");
	draw(&str, 0);
	mlx_hook(str.map.win, 2, 0, key_pressed, &str);
	mlx_hook(str.map.win, 4, 0, mouse_pressed, &str);
	mlx_hook(str.map.win, 17, 0, &ft_close, NULL);
	mlx_loop(str.map.mlx);
}

int			main(int argc, char **argv)
{
	t_str	str;
	int		fd;

	if (argc != 2)
		return (whoops(2));
	if (!(fd = open(argv[1], O_RDONLY))) {
        write(1, "whoops", 6);
        return (whoops(1));
    }
		if (ft_count(fd, &str) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	init_str(&str);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (whoops(1));
	work_coords(fd, &str);
	close(fd);
	draw_str(str);
	return (0);
}
