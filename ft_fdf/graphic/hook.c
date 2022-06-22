/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:07:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:51 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_hooks(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (keysym == 65361)
		data->y_off -= 8;
	else if (keysym == 65363)
		data->y_off += 8;
	else if (keysym == 65364)
		data->x_off += 8;
	else if (keysym == 65362)
		data->x_off -= 8;
	else if (keysym == 119)
		data->rx += 0.1;
	else if (keysym == 115)
		data->rx -= 0.1;
	else if (keysym == 97)
		data->ry -= 0.1;
	else if (keysym == 100)
		data->ry += 0.1;
	else if (keysym == 112)
		data->deg += 1;
	else
		ft_printf("key : %d\n", keysym);
	return (0);
}

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int	mouse_hook(int keysym, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keysym == 4)
		data->zoom++;
	else if (keysym == 5)
		data->zoom--;
	return (0);
}
