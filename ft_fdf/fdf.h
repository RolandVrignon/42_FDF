/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:52:09 by rvrignon          #+#    #+#             */
/*   Updated: 2022/08/01 16:05:09 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_bresenham
{
	int	sx;
	int	sy;
	int	p;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color1;
	int	color2;
	int	d;
	int	dx;
	int	dy;
}	t_bresenham;
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pixel
{
	double			x;
	double			y;
	double			z;
	double			u;
	double			v;
	int				color;
}	t_pixel;

typedef struct s_column
{
	t_pixel				*pixel;
	struct s_column		*next;
}	t_column;

typedef struct s_line
{
	t_column			*column;
	struct s_line		*next;
}	t_line;
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		cur_img;
	int		ww;
	int		wh;
	int		map_width;
	int		map_height;
	int		background;
	int		zoom;
	int		x_off;
	int		y_off;
	double	rx;
	double	ry;
	double	rz;
	double	deg;
	t_img	img;
	t_line	*lines;
}	t_data;

// GRAPHIC FUNCTIONS

int			mlx_main(t_line *lines);

t_data		set_data(t_line *lines);

int			render(t_data *data);

int			handle_keypress(int keysym, t_data *data);

void		render_background(t_data *data);

int			render_map(t_data *data);

void		img_pix_put(t_data *data, int x, int y, int color);

t_bresenham	set_brehensam(t_data *data, t_pixel *origin, t_pixel *dest);

t_pixel		*get_next_pixel(t_data *data, t_pixel *origin, int axis);

void		draw_lines(t_data *data, t_pixel *pixel);

t_pixel		*draw_line(t_data *data, t_pixel *origin);

void		draw_col(t_data *data, t_pixel *origin);

void		bresenham(t_data *data, t_bresenham line);

t_coord		pos(t_data *data, t_pixel *pixel);

int			c(int clr_a, int clr_b, int index);

int			atoi_base(char *str);

// PARSING FUNCTIONS

void		line_lstadd_back(t_line *lines, t_column *column);

void		column_lstadd_back(t_column *column, t_pixel *pixel);

t_column	*column_lstnew(t_pixel *pixel);

t_line		*line_lstnew(t_column *column);

t_pixel		*create_pixel(double i, double j, char *str);

t_line		*assign_coordonates(char **tab, double i, t_line *lines);

t_line		*create_coordonates(char *str);

int			col_lstsize(t_column *lst);

int			line_lstsize(t_line *lst);

// FREE FUNCTIONS

int			free_stuff(char **tab, char *str);

void		free_lines(t_line *lines);

void		free_column(t_column *column);

void		free_double(char **tab);

// Hooks

int			mouse_hook(int keysym, int x, int y, t_data *data);

int			handle_hooks(int keysym, t_data *data);

int			destroy_window(t_data *data);

#endif