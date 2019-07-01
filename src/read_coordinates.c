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

int		*assign_all_coords(char *line, int l_size)
{
	char	**tab;
	int		i;
	int		*cur_line;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (!(cur_line = (int *)malloc(sizeof(int) * l_size)))
		return (NULL);
	while (tab[i] && (i < l_size))
	{
		cur_line[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (cur_line);
}

int		determine_line(char *line, t_map *map, int j)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (check_line(tmp) == 1)
	{
		while(map->tab[i])
			free(map->tab[i++]);
		free(map->line);
		free(tmp);
		return (-1);
	}
	while (tmp[i])
		i++;
	map->line[j] = ft_str_len(tmp);
	free(tmp);
	return (i);
}

t_map	work_coords(int fd, t_map *map)
{
	char	*line;
	int		i;

	if (!(map->tab = (int **)malloc(sizeof(int *) * (map->count_strings))))
		error();
	if (!(map->line = (int *)malloc((sizeof(int *) * (map->count_strings)))))
		error();
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if ((determine_line(line, map, i)) == -1)
			error();
		if (i != 0)
			if (map->line[i] != map->line[i - 1])
				error();
		if ((map->tab[i] = assign_all_coords(line, map->line[i])) == NULL)
			error();
		i++;
		free(line);
	}
	print_coords(*map);
	return (*map);
}
