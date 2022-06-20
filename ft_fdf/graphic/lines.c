/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:26:39 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 16:35:28 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void bresenham(t_data *data, t_bresenham line)
{
	int x0 = line.x1;
	int y0 = line.y1;
	int x1 = line.x2;
	int y1 = line.y2;
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;
	int i;

	i = 200;
	while (1)
	{
		i--;
		if (line.color1 != 0xFFFFFF)
			img_pix_put(data, x0, y0, color_degrade(line.color2, line.color1, i));
		else if (line.color2 != 0xFFFFFF)
			img_pix_put(data, x0, y0, color_degrade(line.color2, line.color1, i));
		else
			img_pix_put(data, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		} 
	}
}

t_pixel *get_next_pixel(t_data *data, t_pixel *origin, int axis)
{
	t_pixel *dest;
	t_pixel *next;
	t_column *column;
	t_line *lines;

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
			break;
	}
	return (dest);
}

t_bresenham set_brehensam(t_data *data, t_pixel *origin, t_pixel *dest)
{
	t_bresenham line;

	line.x1 = pos(data, origin).x;
	line.x2 = pos(data, dest).x;
	line.y1 = pos(data, origin).y;
	line.y2 = pos(data, dest).y;
	line.color1 = origin->color;
	line.color2 = dest->color;
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.x = line.x1;
	line.y = line.y1;
	line.p = 2 * line.dy - line.dx;
	return (line);
}

t_pixel *draw_line(t_data *data, t_pixel *origin)
{
	t_pixel *dest;
	t_bresenham line;

	dest = get_next_pixel(data, origin, 0);
	if (!dest || dest->x == data->map_height - 1)
		return (NULL);
	line = set_brehensam(data, origin, dest);
	bresenham(data, line);
	return (dest);
}

void draw_col(t_data *data, t_pixel *origin)
{
	t_pixel *dest;
	t_bresenham line;

	dest = get_next_pixel(data, origin, 1);
	line = set_brehensam(data, origin, dest);
	bresenham(data, line);
}

void draw_lines(t_data *data, t_pixel *pixel)
{
	pixel = draw_line(data, pixel);
	if (!pixel)
		return;
	draw_col(data, pixel);
}