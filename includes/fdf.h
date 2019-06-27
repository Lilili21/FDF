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

typedef struct  s_map
{
	void				*mlx;
	void				*win;
	int					z;
	int					width;
	int					height;
	int					linesizex;
	int					linesizey;
	int					count_strings;
	int					*line;
	unsigned long		color;
	int					**tab;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					dx;
	int					dy;
	int					incrx;
	int					incry;
	int					turn;
	int					view_y;
	int					view_x;
}               t_map;

void					draw_all_x(t_map *map);
void					draw_all_y(t_map *map);
void	                pixels(t_map *map);
void					negative(t_map *map);
void					positive(t_map *map);
int						error(void);
int						usage(void);
t_map					work_coords(int fd, t_map *map);
int						*assign_all_coords(char *line);
void					ft_map(t_map *map);
void					draw(t_map *map);
int						check_line(char **tab);
t_map					init_map(t_map *map);
int						key_pressed(int keycode, t_map *map);
int						exiterror(void);
void					debugcoords(t_map map);
int						tablen(char **tab);
void	                count_strings(int fd, t_map *map);
int                     error(void);
int ft_close(void *param);
//int                     mouse_pressed(int button, t_map *map);
#endif
