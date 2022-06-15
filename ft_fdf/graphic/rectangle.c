/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 01:09:33 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	p_x(t_data *data, t_pixel *pixel, int height)
{
	int			x_off;
	int			u;

	(void)height;
	x_off = data->height / 2;
	u = (pixel->u * pixel->zoom) + x_off;
	return (u);
}

static	int	p_y(t_data *data, t_pixel *pixel, int width)
{
	int			y_off;
	int			v;

	(void)width;
	y_off = data->width / 2 - (((width * pixel->zoom) / 2) * 2);
	v = (pixel->v * pixel->zoom) + y_off;
	return (v);
}

int	render_map(t_data *data)
{
	t_line		*lines;
	t_column	*column;
	t_pixel		*pixel;
	int			height;
	int			width;

	lines = data->lines;
	height = line_lstsize(lines);
	width = col_lstsize(lines->column);
	while (lines)
	{
		column = lines->column;
		while (column)
		{
			pixel = column->pixel;
			img_pix_put(data, p_y(data, pixel, height), p_x(data, pixel, width),
				pixel->color);
			column = column->next;
		}
		lines = lines->next;
	}
	return (1);
}
