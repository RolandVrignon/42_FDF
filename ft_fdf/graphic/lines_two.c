/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:09:30 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 18:11:08 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_pixel	*draw_line(t_data *data, t_pixel *origin)
{
	t_pixel		*dest;
	t_bresenham	line;

	dest = get_next_pixel(data, origin, 0);
	if (!dest || dest->x == data->map_height - 1)
		return (NULL);
	line = set_brehensam(data, origin, dest);
	bresenham(data, line);
	return (dest);
}

void	draw_col(t_data *data, t_pixel *origin)
{
	t_pixel		*dest;
	t_bresenham	line;

	dest = get_next_pixel(data, origin, 1);
	line = set_brehensam(data, origin, dest);
	bresenham(data, line);
}

void	draw_lines(t_data *data, t_pixel *pixel)
{
	pixel = draw_line(data, pixel);
	if (!pixel)
		return ;
	draw_col(data, pixel);
}
