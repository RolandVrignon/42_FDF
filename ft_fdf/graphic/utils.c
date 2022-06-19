/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:27:33 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/19 19:26:22 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_data	set_data(t_line *lines)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.lines = lines;
	data.win_width = WINDOW_WIDTH;
	data.win_height = WINDOW_HEIGHT;
	data.background = NAVY_PIXEL;
	data.zoom = 8;
	data.map_height = line_lstsize(lines);
	data.map_width = col_lstsize(lines->column);
	return (data);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)data;
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

int	mlx_main(t_line *lines)
{
	t_data	data;

	data = set_data(lines);
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
			
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_mouse_hook(data.win_ptr, &mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	t_img	*img;

	img = &data->img;
	if (x < 0 || x > data->win_height || y < 0 || y > data->win_width)
		return ;
	pixel = img->addr + (x * img->line_len + y * (img->bpp / 8));
	*(int *)pixel = color;
}
