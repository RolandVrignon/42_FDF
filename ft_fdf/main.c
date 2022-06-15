/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:53:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 02:33:42 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
            ft_printf("%d ", pixel->z);
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
    main_minilibx(lines);
    free_lines(lines);
	return (0);
}