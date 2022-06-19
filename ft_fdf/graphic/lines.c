/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:26:39 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/19 18:26:41 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void test(t_data *data, t_bresenham line)
{
	int e;
	int x;
	int y;

	e = line.dx;
	x = line.x1;
	y = line.y1;
	line.dx = e * 2;
	line.dy = line.dy * 2;

	while (x++ != line.x2)
	{
		img_pix_put(data, x, y, WHITE_PIXEL);
		e -= line.dy;
		if (e < 0)
		{
			y++;
			e = e + line.dx;
		}
	}
}

void test_2(t_data *data, t_bresenham line)
{
	int e;
	int x;
	int y;

	e = line.dx;
	x = line.x1;
	y = line.y1;
	line.dx = e * 2;
	line.dy = line.dy * 2;

	while (x++ != line.x2)
	{
		img_pix_put(data, x, y, WHITE_PIXEL);
		e += line.dy;
		if (e < 0)
		{
			y--;
			e = e + line.dx;
		}
	}
}

void test_3(t_data *data, t_bresenham line)
{
	int y;

	y = line.y1;
	while (y < line.y2)
	{
		img_pix_put(data, line.x, y, WHITE_PIXEL);
		y++;
	}
}

void test_4(t_data *data, t_bresenham line)
{
	int e;
	int x;
	int y;

	e = line.dx;
	x = line.x1;
	y = line.y1;
	line.dx = e * 2;
	line.dy = line.dy * 2;

	while (x-- != line.x2)
	{
		img_pix_put(data, x, y, WHITE_PIXEL);
		e += line.dy;
		if (e > 0)
		{
			y++;
			e = e + line.dx;
		}
	}
}

void test_5(t_data *data, t_bresenham line)
{
	int e;
	int x;
	int y;

	e = line.dy;
	x = line.x1;
	y = line.y1;
	line.dy = e * 2;
	line.dx = line.dx * 2;

	while (y++ != line.y2)
	{
		img_pix_put(data, x, y, WHITE_PIXEL);
		e += line.dx;
		if (e < 0)
		{
			x--;
			e = e + line.dy;
		}
	}
}

void test_6(t_data *data, t_bresenham line)
{
	int e;
	int x;
	int y;

	e = line.dy;
	x = line.x1;
	y = line.y1;
	line.dy = e * 2;
	line.dx = line.dx * 2;

	while (y++ != line.y2)
	{
		img_pix_put(data, x, y, WHITE_PIXEL);
		e -= line.dx;
		if (e < 0)
		{
			x++;
			e = e + line.dy;
		}
	}
}

void bresenham(t_data *data, t_bresenham line)
{
	int x0 = line.x1;
	int y0 = line.y1;
	int x1 = line.x2;
	int y1 = line.y2;
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	for (;;)
	{ /* loop */
		img_pix_put(data, x0, y0, WHITE_PIXEL);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		} /* e_xy+e_y < 0 */
	}
	// (void)line;
	// (void)data;

	// if (line.dx != 0)
	// {
	// 	if (line.dx > 0)
	// 	{
	// 		if (line.dy != 0)
	// 		{
	// 			if (line.dy > 0)
	// 			{
	// 				if (line.dx > line.dy)
	// 					test(data, line);
	// 				else
	// 					test_6(data, line);
	// 			}
	// 			else
	// 			{
	// 				if (line.dx > -line.dy)
	// 					test_2(data, line);
	// 				else
	// 					ft_printf("4\n");
	// 			}
	// 		}
	// 		else
	// 		{
	// 			while (line.x < line.x2)
	// 			{
	// 				img_pix_put(data, line.x, line.y, WHITE_PIXEL);
	// 				line.x++;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (line.dy != 0)
	// 		{
	// 			if (line.dy > 0)
	// 			{
	// 				if (-line.dx > line.dy)
	// 					test_4(data, line);
	// 				else
	// 					test_5(data, line);
	// 			}
	// 			else
	// 			{
	// 				if (line.dx <= line.dy)
	// 					ft_printf("8\n");
	// 				else
	// 					ft_printf("9\n");
	// 			}
	// 		}
	// 		else
	// 		{
	// 			ft_printf("10\n");
	// 		}
	// 	}
	// }
	// else
	// {
	// 	if (line.dy != 0)
	// 	{
	// 		if (line.dy > 0)
	// 			test_3(data, line);
	// 		else
	// 			ft_printf("12\n");
	// 	}
	// }
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