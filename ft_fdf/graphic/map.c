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
	double		u;
	double		v;

	u = (pixel->u * data->zoom) + data->x_off;
	v = (pixel->v * data->zoom) + data->y_off;
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
