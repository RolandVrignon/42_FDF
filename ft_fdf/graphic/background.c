/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:26:30 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 17:42:01 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->wh)
	{
		j = 0;
		while (j < data->ww)
		{
			img_pix_put(data, i, j++, data->background);
		}
		++i;
	}
}
