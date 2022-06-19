/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:07:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/19 19:26:38 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int mouse_hook(int keysym, t_data *data)
{
	// if (keysym == 4)
	// 	data.zoom += 1;
	// else if (keysym == 5)
	// 	data.zoom -= 1;
	// (void)data;
	ft_printf("Zoom : %d\n", data->zoom);
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}