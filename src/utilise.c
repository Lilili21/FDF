/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:54:37 by gfoote            #+#    #+#             */
/*   Updated: 2019/06/19 18:54:45 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_str_count(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		i++;
		free(line);
	}
	map->count_strings = i;
}

int		ft_str_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

int		usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
	return (-1);
}

void	print_coords(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.count_strings)
	{
		ft_putstr("Ligne ");
		ft_putnbr(i);
		ft_putstr(" : ");
		while (j < map.line[i])
		{
			ft_putnbr(map.tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}
