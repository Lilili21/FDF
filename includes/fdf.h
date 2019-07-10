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

#define PI 3.14159265359

# define alfa (45.0)
# define beta (0.0)
# define gama (45.0)

# include "libft.h"
# include <math.h>
# include "mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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

typedef struct	s_xyz2{
	double			x;
	double			y;
	double			z;
}				t_xyz2;

typedef struct	s_map{

	void		*img;
	int 		*data;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			width_img;
	int			height_img;
	int 		trash;

}				t_map;

typedef struct	s_str
{
	t_map		map;
	t_prm		prm;
	t_xyz		*xyz;
	t_xyz2		*xyz_tmp;
	int			length;
	int			count_strings;
	int			count_elems;

	double		delta_x;
	double		delta_y;
	double		x_alfa;
	double		y_alfa;
	double		z_alfa;

}               t_str;



/*
 * main.c
 */
t_str			init_str(t_str *str);

/*
 * read_coordinates.c
 */
int				ft_count(int fd, t_str *str);
void			work_coords(int fd, t_str *str);
//void			assign_all_coords(t_str *str, char *line, int num_line);
void			assign_xy(t_str *str);

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
void	pixels(t_str *str, int i, int j);

/*
 * hook.c
 */
int mouse_pressed(int button, int x, int y, void *param);
int key_pressed(int keycode, t_str *str);
int                     ft_close(void *param);

/*
 * draw.c
 */
void			draw(t_str *str, int turn);

/*
 * rotate.c
 */
void rotate_x(t_str *str, int i, int check);
void rotate_y(t_str *str, int i, int check);
void rotate_z(t_str *str, int i, int check);

#endif
