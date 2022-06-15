/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:27:33 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 00:54:48 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int main_minilibx(t_line *lines)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.lines = lines;
	data.width = WINDOW_WIDTH;
	data.height = WINDOW_HEIGHT;
	data.background = NAVY_PIXEL;
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width, data.height, "Welcome FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.width, data.height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
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
	char    *pixel;
	t_img	*img;

	img = &data->img;
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return ;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}