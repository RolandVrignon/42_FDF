/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:28 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/14 20:05:45 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int render_rect(t_img *img, t_rect rect)
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

// int make_axe_isometric(t_img *img, t_axe axe)
// {
// 	int i;
// 	int j;
// 	int k;

// 	i = axe.x;
// 	j = axe.y;
// 	k = axe.z;
	
// }

int render_axe(t_img *img, t_axe axe)
{
	int i;
	int j;
	
	i = axe.y;
	j = axe.x;
	while (i < axe.y + (WINDOW_HEIGHT - axe.y))
		img_pix_put(img, j, i++, RED_PIXEL);
	i = axe.y;
	j = axe.x;
	while (j < axe.x + (WINDOW_WIDTH - axe.x))
		img_pix_put(img, j++, i, RED_PIXEL);
	return (0);
}