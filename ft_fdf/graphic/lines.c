/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:26:39 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 20:45:31 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	b_line(t_data *data, t_bresenham line)
{
	while (line.x <= line.x2 && line.y <= line.y2)
	{
		if(line.p >= 0)
		{
			img_pix_put(data, line.x, line.y, WHITE_PIXEL);
			line.y += 1;
			line.p = line.p + 2 * line.dy -  2 * line.dx;
		}
		else
		{
			img_pix_put(data, line.x, line.y, WHITE_PIXEL);
			line.p = line.p + 2 * line.dy;
			line.x += 1;
		}
	}
}

t_pixel *get_next_pixel(t_data *data, t_pixel *origin, int axis)
{
	t_pixel *dest;
	t_pixel *next;
	t_column *column;
	t_line	*lines;

	dest = NULL;
	lines = data->lines;
	while(lines && !dest)
	{
		column = lines->column;
		while (column && !dest)
		{
			next = column->pixel;
			if (!axis && next->x == origin->x && next->y == origin->y + 1)
				dest = next;
			if (axis == 1 && next->x == origin->x+1 && next->y == origin->y)
				dest = next;
			column = column->next;
		}
		lines = lines->next;
		if (!lines)
			break; 
	}
	return (dest);
}

t_bresenham swap(t_bresenham line)
{
	int xtmp;
	int ytmp;

	xtmp = line.x1;
	ytmp = line.y1;
	line.x1 = line.x2;
	line.y1 = line.y2;
	line.x2 = xtmp;
	line.y2 = ytmp;
	return (line);
}

t_bresenham set_brehensam(t_data *data, t_pixel *origin, t_pixel *dest)
{
	t_bresenham line;

	line.x1 = pos(data, origin).x;
	line.x2 = pos(data, dest).x;
	line.y1 = pos(data, origin).y;
	line.y2 = pos(data, dest).y;
	if (line.x1 > line.x2)
		line = swap(line);
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.x = line.x1;
	line.y = line.y1;
	line.p = 2 * line.dy - line.dx;
	return (line);
}

t_pixel	*draw_line(t_data *data, t_pixel *origin)
{
	t_pixel		*dest;
	t_bresenham line;
	
	dest = get_next_pixel(data, origin, 0);
	if (!dest || dest->x == data->map_height - 1)
		return (NULL);
	line = set_brehensam(data, origin, dest);
	// (void)line;
	b_line(data, line);
	return (dest);
}

void	draw_col(t_data *data, t_pixel *origin)
{
	t_pixel *dest;
	t_bresenham line;
	
	dest = get_next_pixel(data, origin, 1);
	line = set_brehensam(data, origin, dest);
	// (void)line;
	b_line(data, line);
}

void	draw_lines(t_data *data, t_pixel *pixel)
{	
	pixel = draw_line(data, pixel);
	if (!pixel)
		return ;
	draw_col(data, pixel);
}