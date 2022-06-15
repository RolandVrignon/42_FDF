/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 03:46:15 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int render_map(t_img *img, t_line *lines)
{
    int			x_off;
	int			y_off;
	t_column	*column;
    t_pixel 	*pixel;
    
	x_off = WINDOW_HEIGHT / 2 - line_lstsize(lines);
	y_off = WINDOW_WIDTH / 2 - col_lstsize(lines->column);
    while(lines)
    {
        column = lines->column;
        while(column)
        {
            pixel = column->pixel;
			if (pixel->z == 0)
            	img_pix_put(img, pixel->u + y_off, pixel->v + x_off, GREEN_PIXEL);
			else
				img_pix_put(img, pixel->u + y_off, pixel->v + x_off, RED_PIXEL);
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