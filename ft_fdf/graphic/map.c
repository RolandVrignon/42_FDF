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
	double		deg;
	double		tmp;
	double		u;
	double		v;

	tmp = pixel->u;
	deg = data->deg * M_PI_4 / 50;
	pixel->u = ((pixel->x * data->rx) - 1.4 * pixel->z) / sqrt(2);
	pixel->v = ((pixel->x * data->rx) + 2 * (pixel->y * data->ry) + 1.4 * pixel->z) / sqrt(6);
	u = pixel->u + (pixel->u * cos(deg) + pixel->v * sin(deg));
	v = pixel->v + (-tmp * sin(deg) + pixel->v * cos(deg));
	u = (u * data->zoom) + data->x_off;
	v = (v* data->zoom) + data->y_off;
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
			draw_lines(data, pixel);
			column = column->next;
		}
		lines = lines->next;
	}
	return (1);
}
