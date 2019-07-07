/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:50:36 by swarner           #+#    #+#             */
/*   Updated: 2019/04/21 21:50:38 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include "mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map{
    void		*mlx;
    void		*win;

	void		*img;
	int 		trash;
	int *		data;
    int			width;
    int			height;
}				t_map;

typedef struct	s_prm{
    int			start_x;
    int			start_y;
    int			linesizex;
    int			linesizey;
    int			zoom;

	int			dx;
	int			dy;
	int			incrx;
	int			incry;
}               t_prm;

typedef struct	s_xyz{
    int			x;
    int			y;
    int			z;
}				t_xyz;

typedef struct	s_str
{
    t_prm		prm;
    t_xyz		*xyz;
    int			length; //count_elems/cout_strings
	int			count_strings;
    int			count_elems;

	int			x1;
	int			x2;
	int			y1;
	int			y2;

	int			turn;
	int			view_y;
	int			view_x;
}               t_str;

/*
 * main.c
 */
t_str			init_str(t_str *str, t_map *map);

/*
 * read_coordinates.c
 */
int				ft_count(int fd, t_str *str);
void			work_coords(int fd, t_str *str);
void			assign_all_coords(t_str *str, char *line, int num_line);

/*
 * utilise.c
 */
int				ft_str_len(char **tab);
void			print_coords(t_str str);
int				error(void);
int				usage(void);

/*
 * Bresenham.c
 */
void	pixels(t_str *str, t_map *map, int i, int j);

/*
 * hook.c
 */
int                   	mouse_pressed(int button, t_str *str, t_map *map);
int						key_pressed(int keycode, t_str *str, t_map *map);
int                     ft_close(void *param);

/*
 * draw.c
 */
void			draw(t_str *str, t_map *map, int turn);
#endif
