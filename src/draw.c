/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:15:27 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:20:35 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_commands(t_str *str)
{
	mlx_string_put(str->map.mlx, str->map.win, 90, 10, 0x00FFFFFF,
			"Key commands");
	mlx_string_put(str->map.mlx, str->map.win, 50, 30, 0x00FFFFFF,
			"change level    + -");
	mlx_string_put(str->map.mlx, str->map.win, 50, 70, 0x00FFFFFF,
			"change position ^ v < >");
	mlx_string_put(str->map.mlx, str->map.win, 50, 50, 0x00FFFFFF,
			"change size     Up Down");
	mlx_string_put(str->map.mlx, str->map.win, 50, 90, 0x00FFFFFF,
			"rotate x        W E");
	mlx_string_put(str->map.mlx, str->map.win, 50, 110, 0x00FFFFFF,
			"rotate y        S D");
	mlx_string_put(str->map.mlx, str->map.win, 50, 130, 0x00FFFFFF,
			"rotate z        X C");
	mlx_string_put(str->map.mlx, str->map.win, 390, 10, 0x00FFFFFF,
			"Mouse commands");
	mlx_string_put(str->map.mlx, str->map.win, 350, 30, 0x00FFFFFF,
			"change level    ^ Scroll v ");
	mlx_string_put(str->map.mlx, str->map.win, 350, 50, 0x00FFFFFF,
			"change size     > Click < ");
}

void	draw_cycle(t_str *str)
{
	int i;

	i = 0;
	while (i < str->count_elems - 1)
	{
		if ((i + 1) % str->length == 0)
			i++;
		draw_img(str, i, i + 1);
		i++;
	}
	i = 0;
	while (i < str->count_elems - str->length)
	{
		draw_img(str, i, i + str->length);
		i++;
	}
}

void	draw(t_str *str, int turn)
{
	str->map.img = mlx_new_image(str->map.mlx, str->map.width_img,
			str->map.height_img);
	str->map.data = (int *)mlx_get_data_addr(str->map.img,
			&(str->map.trash), &(str->map.trash), &(str->map.trash));
	draw_commands(str);
	if (turn != 0)
		assign_xy(str);
	if (!(str->xyz_tmp = (t_xyz *)malloc(sizeof(t_xyz) * (str->count_elems))))
		error();
	find_centr(str);
	draw_cycle(str);
	free(str->xyz_tmp);
	mlx_put_image_to_window(str->map.mlx, str->map.win, str->map.img, 50, 150);
}
