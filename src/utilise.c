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

/*
**	Print all (debug)
*/

void	debugcoords(t_map map)
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

/*
**	Error detect
*/

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

/*
**	Error case
*/

int		exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

/*
**	Usage
*/

int		usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
	return (-1);
}

/*
**	Gives number of elements in a table of string.
*/

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}