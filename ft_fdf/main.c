/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:53:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/14 01:35:21 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }

int main(int ac, char **av)
{
    int     fd;
    char    *str;

    if (ac != 2)
        return (1);
    fd = open(av[1], O_RDONLY);
    str = get_next_line(fd);
    while (str != NULL)
    {
        ft_printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    return (1);
}