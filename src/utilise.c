/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:34:26 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:37:34 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	print_coords(t_str str)
{
	int i;
	int j;
	int elem_in_string;
	int t;

	i = 0;
	j = 0;
	t = 0;
	elem_in_string = str.count_elems / str.count_strings;
	while (j < str.count_elems)
	{
		ft_putstr("Ligne ");
		ft_putnbr(t);
		ft_putstr(" : ");
		while (i < elem_in_string)
		{
			ft_putnbr(str.xyz[j].z);
			ft_putchar(' ');
			j++;
			i++;
		}
		ft_putstr("\n");
		i = 0;
		t++;
	}
}
