/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:52:09 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 01:29:11 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define NAVY_PIXEL 0x222947

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
}	t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

typedef struct s_pixel
{
	int			x;
	int			y;
	int			z;
	int			u;
	int			v;
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


void	render_background(t_img *img, int color);

int 	render_rect(t_img *img, t_rect rect);

int		handle_keypress(int keysym, t_data *data);

void	img_pix_put(t_img *img, int x, int y, int color);

t_line	*create_coordonates(char *str);

int 	free_stuff(char **tab, char *str);

void	free_lines(t_line *lines);

#endif