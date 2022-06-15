/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:53:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 02:05:41 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, NAVY_PIXEL);
	render_rect(&data->img, (t_rect){(WINDOW_WIDTH / 2) - 50 , (WINDOW_HEIGHT / 2) - 50, 100, 100, GREEN_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int main_minilibx(char * str)
{
	t_data	data;

	(void)str;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
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

void print_lines(t_line *lines)
{
    int i;
    t_column *column;
    t_pixel  *pixel;
    
    i = 0;
    while(lines)
    {
        column = lines->column;
        while(column)
        {
            pixel = column->pixel;
            ft_printf("{%d, %d} ", pixel->u, pixel->v);
            column = column->next;
            i++;
        }
        ft_printf("\n");
        lines = lines->next;
    }
}

int	main(int ac, char **av)
{
	t_line *lines;

    (void)av;
	if (ac < 2 || ac > 2)
	{
		ft_printf("Error, not enough or too much arguments\n");
		return (0);
	}
    lines = create_coordonates(av[1]);
    print_lines(lines);
    free_lines(lines);
	return (0);
}