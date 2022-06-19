/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:2:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 20:03:16 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	pos(t_data *data, t_pixel *pixel)
{
	t_coord		test;
	double			x_off;
	double			u;
	double			y_off;
	double			v;

	x_off = data->win_height / 2;
	u = (pixel->u * data->zoom) + x_off;
	y_off = data->win_width / 2 - data->map_width * data->zoom / 2;
	v = (pixel->v * data->zoom) + y_off;
	test.x = u;
	test.y = v;
	return (test);
}

int	render_map(t_data *data)
{
	t_line		*lines;
	t_column	*column;
	t_pixel		*pixel;

	lines = data->lines;
	while (lines)
	{
		column = lines->column;
		while (column)
		{
			pixel = column->pixel;
			// img_pix_put(data, pos(data, pixel).x, pos(data, pixel).y, pixel->color);
			draw_lines(data, pixel);
			column = column->next;
		}
		lines = lines->next;
	}
	return (1);
}
