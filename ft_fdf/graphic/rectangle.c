/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 00:23:03 by rvrignon         ###   ########.fr       */
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

// void	draw_line(t_img *canevas, t_coord origin, t_coord dest)
// {
// 	int	dx;
// 	int	dy;
// 	int	e;

// 	dx = (dest.x - origin.x);
// 	dy = (dest.y - origin.y);
// 	e = dest.x - origin.x;
// 	while (origin.x < dest.x)
// 	{
// 		img_pix_put(canevas, origin.y, origin.x, WHITE_PIXEL);
// 		e -= dy;
// 		if (e <= 0)
// 		{
// 			origin.y++;
// 			e += dx;
// 		}
// 		origin.x++;
// 	}
// }

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
			if (!column)
				break;
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