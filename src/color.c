/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:35:45 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/23 11:23:23 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		check_l_color(char *tab, int j)
{
	int k;

	if (tab[j + 1] == '0' && tab[j + 2] == 'x')
	{
		j = j + 3;
		k = 0;
		while (tab[j])
		{
			if ((tab[j] >= '0' && tab[j] <= '9') ||
				(tab[j] >= 'A' && tab[j] <= 'F') ||
				(tab[j] >= 'a' && tab[j] <= 'f'))
			{
				k++;
				j++;
			}
			else
				return (1);
		}
		if (k != 6)
			return (1);
	}
	return (j);
}
/*
int percent(double curr, t_str *str)
{
	int Blue = 0x0000FF;
	int Green = 0x00FF00;

	double percentage;
	double percentage1;

	percentage = curr / str->max_z;
	percentage1 = curr / str->min_z;
	if (percentage1 == 1)
		return Blue;
	else if (percentage1 > 1 && percentage < 1)
		return


}*/

int		get_basic_color(t_str *str, int i)
{
	if (str->xyz[i].color == 0x000000)
	{
		if (str->xyz[i].z == str->max_z)
			return (0xFFFFFF);
		else if (str->xyz[i].z > (str->max_z - str->min_z) / 3 * 2)
			return (0x00FF00);
		else if (str->xyz[i].z > (str->max_z - str->min_z) / 3)
			return (0x00BFFF);
		else if (str->xyz[i].z > str->min_z)
			return (0xFF00FF);
		else
			return (0xFFA500);
	}
	return (str->xyz[i].color);
	//printf("color = %i\n", percent(str->xyz[i].z, str));
	 //(percent(str->xyz[i].z, str));
}

int		ft_get_color(char *str)
{
	char	*result;
	int		result_t;
	int		i;

	i = 0;
	result = ft_strchr(str, ',');
	while (i++ < 3)
		result++;
	result_t = ft_atoi_base(result, 16);
	return (result_t);
}

