/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:26:39 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 01:55:15 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	swap(t_coord origin, t_coord dest)
{
	int xtmp;
	int ytmp;

	xtmp = origin.x;
	ytmp = origin.y;
	origin.x = dest.x;
	origin.y = dest.y;
	dest.x = xtmp;
	dest.y = ytmp;
}

void	draw_lines(t_data *data, t_coord origin, t_coord dest)
{
	int dx;
	int dy;
	int y;


	dx = dest.x - origin.x;
	dy = dest.y - origin.y;
	if (origin.x > dest.x)
		swap(origin, dest);
	while(origin.x < dest.x)
	{
		y = dest.y + dy * (origin.x - dest.x) / dx;
		img_pix_put(data, origin.x, y, WHITE_PIXEL);
	}
}
