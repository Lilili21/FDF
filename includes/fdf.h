/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:29:45 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 17:41:49 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
#include <MacTypes.h>

typedef struct	s_prm
{
	int			move_x;
	int			move_y;
	int			linesizex;
	int			linesizey;
	int			zoom;
	int			dx;
	int			dy;
	int			incrx;
	int			incry;
}				t_prm;

typedef struct	s_xyz
{
	double		x;
	double		y;
	double		z;
}				t_xyz;

typedef struct	s_map
{
	void		*img;
	int			*data;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			width_img;
	int			height_img;
	int			trash;
}				t_map;

typedef struct	s_str
{
	t_map		map;
	t_prm		prm;
	t_xyz		*xyz;
	t_xyz		*xyz_tmp;
	int			length;
	int			count_strings;
	int			count_elems;
	double		delta_x;
	double		delta_y;
	double		x_alfa;
	double		y_alfa;
	double		z_alfa;
}				t_str;

t_str			init_str(t_str *str);
int				ft_count(int fd, t_str *str);
void			work_coords(int fd, t_str *str);
void			assign_xy(t_str *str);
int				ft_str_len(char **tab);
void			print_coords(t_str str);
int				error(void);
int				usage(void);
int				check_line(char **tab);
void			draw_img(t_str *str, int i, int j);
int				mouse_pressed(int button, int x, int y, t_str *str);
int				key_pressed(int keycode, t_str *str);
int				ft_close(void *param);
void			draw(t_str *str, int turn);
void			rotate(t_str *str, int i);
void			find_centr(t_str *str);
void			normalize(t_str *str, int i);

#endif
