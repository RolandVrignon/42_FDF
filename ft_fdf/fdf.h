/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:52:09 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 01:20:58 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define MLX_ERROR 1

# define RED_PIXEL 0xff79c6
# define GREEN_PIXEL 0x50fa7b
# define NAVY_PIXEL 0x282a36
# define WHITE_PIXEL 0xFFFFFF

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
	int		width;
	int		height;
	int		background;
	int		zoom;
	t_img	img;
	t_line	*lines;
}	t_data;

// GRAPHIC FUNCTIONS

t_data		set_data(t_line *lines);

int			render(t_data *data);

int			main_minilibx(t_line *lines);

int			handle_keypress(int keysym, t_data *data);

void		render_background(t_data *data);

int			render_map(t_data *data);

void		img_pix_put(t_data *data, int x, int y, int color);

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

#endif