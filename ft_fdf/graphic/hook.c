/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:07:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 17:44:00 by rvrignon         ###   ########.fr       */
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
	else if (keysym == 113)
		data->zoom++;
	else if (keysym == 119)
		data->zoom--;
	else if (keysym == 65361)
		data->y_off -= 8;
	else if (keysym == 65363)
		data->y_off += 8;
	else if (keysym == 65364)
		data->x_off += 8;
	else if (keysym == 65362)
		data->x_off -= 8;
	else
		ft_printf("Keypress: %d\n", keysym);
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
