#include "fdf.h"

void rotate_x(t_str *str, int i, int check)
{
	int prev_x;
	int prev_y;
	int prev_z;

	if(check == 0) {
		prev_x = str->xyz[i].x;
		prev_y = str->xyz[i].y;
		prev_z = str->xyz[i].z;
	}
	else
	{
		prev_x = str->xyz_tmp[i].x;
		prev_y = str->xyz_tmp[i].y;
		prev_z = str->xyz_tmp[i].z;
	}
	str->xyz_tmp[i].x = prev_x;
	str->xyz_tmp[i].y = sin(str->x_alfa) * prev_z * str->prm.zoom + prev_y * cos(str->x_alfa);
	str->xyz_tmp[i].z = -prev_y *sin(str->x_alfa) + prev_z * cos(str->x_alfa);
}

void rotate_y(t_str *str, int i, int check)
{
	int prev_x;
	int prev_y;
	int prev_z;

	if(check == 0) {
		prev_x = str->xyz[i].x;
		prev_y = str->xyz[i].y;
		prev_z = str->xyz[i].z;
	}
	else
	{
		prev_x = str->xyz_tmp[i].x;
		prev_y = str->xyz_tmp[i].y;
		prev_z = str->xyz_tmp[i].z;
	}
	str->xyz_tmp[i].x = prev_x * cos(str->y_alfa) + prev_z * sin(str->y_alfa);
	str->xyz_tmp[i].y = prev_y;
	str->xyz_tmp[i].z = -prev_x * sin(str->y_alfa) +prev_z * cos(str->y_alfa);
}

void rotate_z(t_str *str, int i, int check)
{
	int prev_x;
	int prev_y;
	int prev_z;

	if(check == 0) {
		prev_x = str->xyz[i].x;
		prev_y = str->xyz[i].y;
		prev_z = str->xyz[i].z;
	}
	else
	{
		prev_x = str->xyz_tmp[i].x;
		prev_y = str->xyz_tmp[i].y;
		prev_z = str->xyz_tmp[i].z;
	}
	str->xyz_tmp[i].x = prev_x * cos(str->z_alfa) - prev_y * sin(str->z_alfa);
	str->xyz_tmp[i].y = -prev_x * sin(str->z_alfa) +prev_y * cos(str->z_alfa);
	str->xyz_tmp[i].z = prev_z;
}