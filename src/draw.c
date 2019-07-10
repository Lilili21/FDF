#include "fdf.h"
#include <stdio.h>


void	centr(t_str *str, int turn) {
	int i;

	i = str->count_elems / 2;
	rotate_x(str, i, 0);
	rotate_y(str, i, 1);
	rotate_z(str, i, 1);
	if (turn == 0) {
		str->delta_x = str->xyz_tmp[i].x - str->map.width_img / 2;
		str->delta_y = str->xyz_tmp[i].y - str->map.height_img / 2;
	}
	else
	{
		str->delta_x = str->xyz_tmp[i].x - str->map.width_img / 2 - str->prm.start_x;
		str->delta_y = str->xyz_tmp[i].y - str->map.height_img / 2 - str->prm.start_y;
	}
	printf("centr i = %i x = %d, y = %d\n", i, str->xyz_tmp[i].x, str->xyz_tmp[i].y);
}


void	draw(t_str *str, int turn)
{
	int i;
	str->map.img = mlx_new_image(str->map.mlx, str->map.width_img, str->map.height_img);
	str->map.data = (int *)mlx_get_data_addr(str->map.img, &(str->map.trash), &(str->map.trash), &(str->map.trash));
	mlx_string_put(str->map.mlx, str->map.win, 50, 50, 0x00FFFFFF, "change level    + -" );
	mlx_string_put(str->map.mlx, str->map.win, 50, 70, 0x00FFFFFF, "change position ^ v < >" );
	mlx_string_put(str->map.mlx, str->map.win, 50, 90, 0x00FFFFFF, "change size     Up Down" );

	if (turn != 0)
		assign_xy(str);
	i = 0;
	if (!(str->xyz_tmp = (t_xyz2 *)malloc(sizeof(t_xyz2) * (str->count_elems))))
		error();
	centr(str, turn);
	while(i < str->count_elems - 1)
	{
		if ((i + 1) % str->length == 0)
			i++;
		pixels(str, i, i + 1);
		i++;
	}
	i = 0;
	while(i < str->count_elems - str->length)
	{
		pixels(str, i, i + str->length);
		i++;
	}
	mlx_put_image_to_window(str->map.mlx, str->map.win, str->map.img, 50 , 130);
}