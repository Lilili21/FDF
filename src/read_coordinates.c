/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:26:30 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:32:44 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_z(t_str *str, char *line, int num_line)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_strsplit(line, ' ');
	j = num_line * str->length + i;
	while (tab[i] && i < str->length)
	{
		str->xyz[j].z = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
		j++;
	}
	free(tab);
}

void	assign_xy(t_str *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < str->count_elems)
	{
		i++;
		str->xyz[j].x = 0;
		str->xyz[j].y = (i - 1) * (str->prm.linesizey);
		j++;
		while (j < str->length * i)
		{
			str->xyz[j].x = str->xyz[j - 1].x + str->prm.linesizex;
			str->xyz[j].y = str->xyz[j - 1].y;
			j++;
		}
	}
}

void	work_coords(int fd, t_str *str)
{
	char	*line;
	int		i;

	if (!(str->xyz = (t_xyz *)malloc(sizeof(t_xyz) * (str->count_elems))))
		error();
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		assign_z(str, line, i++);
		free(line);
	}
	assign_xy(str);
	print_coords(*str);
}

void	ft_clear(char *line, char **tmp)
{
	int i;

	i = 0;
	free(line);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int		ft_count(int fd, t_str *str)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	line = NULL;
	str->count_elems = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		i++;
		tmp = ft_strsplit(line, ' ');
		if (check_line(tmp) == 1 ||
				((str->count_elems + ft_str_len(tmp)) / i != ft_str_len(tmp)))
		{
			ft_clear(line, tmp);
			return (error());
		}
		str->count_elems += ft_str_len(tmp);
		ft_clear(line, tmp);
	}
	str->count_strings = i;
	if (str->count_strings == 0)
		return (error());
	str->length = str->count_elems / str->count_strings;
	return (0);
}
