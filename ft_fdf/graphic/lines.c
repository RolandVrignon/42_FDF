/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:26:39 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 18:09:58 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham(t_data *data, t_bresenham line)
{
	int	i;
	int	e2;

	i = 200;
	while (1)
	{
		i--;
		if (line.color1 != 0xFFFFFF || line.color2 != 0xFFFFFF)
			img_pix_put(data, line.x1, line.y1, c(line.color2, line.color1, i));
		else
			img_pix_put(data, line.x1, line.y1, 0xFFFFFF);
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		e2 = 2 * line.p;
		if (e2 >= line.dy)
		{
			line.p += line.dy;
			line.x1 += line.sx;
		}
		if (e2 <= line.dx)
		{
			line.p += line.dx;
			line.y1 += line.sy;
		}
	}
}

t_pixel	*get_next_pixel(t_data *data, t_pixel *origin, int axis)
{
	t_pixel		*dest;
	t_pixel		*next;
	t_column	*column;
	t_line		*lines;

	dest = NULL;
	lines = data->lines;
	while (lines && !dest)
	{
		column = lines->column;
		while (column && !dest)
		{
			next = column->pixel;
			if (!axis && next->x == origin->x && next->y == origin->y + 1)
				dest = next;
			if (axis == 1 && next->x == origin->x + 1 && next->y == origin->y)
				dest = next;
			column = column->next;
		}
		lines = lines->next;
		if (!lines)
			break ;
	}
	return (dest);
}

t_bresenham	set_brehensam(t_data *data, t_pixel *origin, t_pixel *dest)
{
	t_bresenham	line;

	line.x1 = pos(data, origin).x;
	line.x2 = pos(data, dest).x;
	line.y1 = pos(data, origin).y;
	line.y2 = pos(data, dest).y;
	line.color1 = origin->color;
	line.color2 = dest->color;
	line.dx = abs(line.x2 - line.x1);
	line.dy = -abs(line.y2 - line.y1);
	line.sx = -1;
	line.sy = -1;
	if (line.x1 < line.x2)
		line.sx = 1;
	if (line.y1 < line.y2)
		line.sy = 1;
	line.p = line.dy + line.dx;
	return (line);
}
