/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:24:01 by gfoote            #+#    #+#             */
/*   Updated: 2019/06/27 20:24:13 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_line(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
			if (tab[i][j] == '-')
			{
				j++;
				while (tab[i][j] != '\0')
				{
					if (tab[i][j] < '0' || tab[i][j] > '9')
						return (1);
					j++;
				}
			}
			else if (tab[i][j] >= '0' && tab[i][j] <= '9')
				j++;
			else
				return (1);
		i++;
	}
	return (0);
}

void	assign_all_coords(t_str *str, char *line, int num_line)
{
	char	**tab;
	int		i;
	int		j;
	int 	size;

	i = 0;
	size = str->count_elems / str->count_strings;
	tab = ft_strsplit(line, ' ');
	j = num_line * size + i;
	while (tab[i] && i < size)
	{
		str->xyz[j].x = str->prm.start_x + i * str->prm.linesizex;
		str->xyz[j].y = str->prm.start_y + num_line * str->prm.linesizey;
		str->xyz[j].z = ft_atoi(tab[i]);
		//str->xyz[j].color = 0x00FFFFFF;
		free(tab[i]);
		i++;
		j++;
	}
	free(tab);
}

void	work_coords(int fd, t_str *str)
{
	char	*line;
	int i;

	if (!(str->xyz = (t_xyz *)malloc(sizeof(t_xyz) * (str->count_elems))))
		error();
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		assign_all_coords(str, line, i);
		i++;
		free(line);
	}
	//print_coords(*str);
}

int		ft_count(int fd, t_str *str)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	line = NULL;

	str->count_elems = 0;
	str->count_strings = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		i++;
		tmp = ft_strsplit(line, ' ');
		if (check_line(tmp) == 1 || ((str->count_elems + ft_str_len(tmp))/ i
									  != ft_str_len(tmp)))
		{
			free(line);
			free(tmp);
			return (error());
		}
		str->count_elems += ft_str_len(tmp);
		free(tmp);
		free(line);
	}
	str->count_strings = i;
	str->length = str->count_elems/str ->count_strings;
	return (0);
}
