/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:07:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 12:39:47 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int handle_hooks(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 113)
		data->zoom++;
	if (keysym == 119)
		data->zoom--;
	// ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int mouse_hook(int keysym, t_data *data)
{
	if (keysym == 4)
		data->zoom++;
	else if (keysym == 5)
		data->zoom--;
	return (0);
}