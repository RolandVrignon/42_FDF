/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:52:09 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 14:23:29 by rvrignon         ###   ########.fr       */
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

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define NAVY_PIXEL 0x222947
typedef struct s_pixel
{
	int			x;
	int			y;
	int			z;
	int			u;
	int			v;
	int			zoom;
	int			color;
}	t_pixel;

typedef struct s_column
{
	t_pixel				*pixel;
	struct s_column 	*next;
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
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_line	*lines;
}	t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

// GRAPHIC FUNCTIONS

int			render(t_data *data);

int			main_minilibx(t_line *lines);

int			handle_keypress(int keysym, t_data *data);

void		render_background(t_img *img, int color);

int 		render_map(t_img *img, t_line *lines);

int 		render_rect(t_img *img, t_rect rect);

void		img_pix_put(t_img *img, int x, int y, int color);

// PARSING FUNCTIONS

void		line_lstadd_back(t_line *lines, t_column *column);

void		column_lstadd_back(t_column *column, t_pixel *pixel);

t_column	*column_lstnew(t_pixel *pixel);

t_line		*line_lstnew(t_column *column);

t_pixel 	*create_pixel(int i, int j, char *str);

t_line		*assign_coordonates(char **tab, int i, t_line *lines);

t_line		*create_coordonates(char *str);

int			col_lstsize(t_column *lst);

int			line_lstsize(t_line *lst);

// FREE FUNCTIONS

int 		free_stuff(char **tab, char *str);

void		free_lines(t_line *lines);

#endif