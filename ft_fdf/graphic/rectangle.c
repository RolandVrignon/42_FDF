/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 15:47:34 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int p_x(t_pixel *pixel, int height)
{
	int			x_off;
	int			u;

	(void)height;
	x_off = WINDOW_HEIGHT / 2 - (((height * pixel->zoom) / 4));
	u = (pixel->u * pixel->zoom) + x_off;
	return (u);
}

static	int p_y(t_pixel *pixel, int width)
{
	int			y_off;
	int			v;

	(void)width;
	y_off = WINDOW_WIDTH / 2 - (((width * pixel->zoom) / 2) * 2);
	v = (pixel->v * pixel->zoom) + y_off;
	return (v);
}

int render_map(t_img *img, t_line *lines)
{
	t_column	*column;
    t_pixel 	*pixel;
	int			height;
	int			width;

	height = line_lstsize(lines);
	width = col_lstsize(lines->column);
    while(lines)
    {
        column = lines->column;
        while(column)
        {
            pixel = column->pixel;
			if (pixel->z == 0)
            	img_pix_put(img, p_y(pixel, height), p_x(pixel, width), GREEN_PIXEL);
			else
				img_pix_put(img, p_y(pixel, height), p_x(pixel, width), RED_PIXEL);
            column = column->next;
        }
        lines = lines->next;
    }
	return (1);
}

int 	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}