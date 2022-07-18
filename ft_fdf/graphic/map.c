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

t_coord	pos(t_data *d, t_pixel *p)
{
	t_coord		test;
	double		deg;
	double		tmp;
	double		u;
	double		v;

	tmp = p->u;
	deg = d->deg * M_PI_4 / 50;
	p->u = ((p->x * d->rx) - d->rz * p->z) / sqrt(2);
	p->v = ((p->x * d->rx) + 2 * (p->y * d->ry) + d->rz * p->z) / sqrt(6);
	u = p->u + (p->u * cos(deg) + p->v * sin(deg));
	v = p->v + (-tmp * sin(deg) + p->v * cos(deg));
	u = (u * d->zoom) + d->x_off;
	v = (v * d->zoom) + d->y_off;
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
