
#include "fdf.h"

void	count_strings(int fd, t_map *map)
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

int		determine_line(char *line, t_map *map, int count_strings)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (check_line(tmp) == 1)
		return (-1);
	while (tmp[i])
		i++;
	map->line[count_strings] = tablen(tmp);
	free(tmp);
	return (i);
}1
/*
**	Malloc and store a line in tab
*/

t_map	work_coords(int fd, t_map *map)
{
	char	*line;
	int		count_strings;

	if (!(map->tab = (int **)malloc(sizeof(int *) * (map->count_strings))))
		exiterror();
	if (!(map->line = (int *)malloc((sizeof(int *) * (map->count_strings)))))
		exiterror();
	line = NULL;
	count_strings = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((determine_line(line, map, count_strings)) == -1)
			exiterror();
		if (count_strings != 0)
			if (map->line[count_strings] != map->line[count_strings - 1])
				exiterror();
		if ((map->tab[count_strings] = assign_all_coords(line)) == NULL)
			exiterror();
		count_strings++;
		free(line);
	}
	debugcoords(*map);
	return (*map);
}

/*
**	Transforms a line into a tab of int
*/

int		*assign_all_coords(char *line)
{
	char	**tab;
	int		i;
	int		*oneline;
	int		eastmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	eastmax = tablen(tab);
	free(tab);
	if (!(oneline = (int *)malloc(sizeof(int) * eastmax)))
		return (NULL);
	while (tab[i] && (i < eastmax))
	{
		oneline[i] = ft_atoi(tab[i]);
		i++;
	}
	//free(line);
	return (oneline);
}