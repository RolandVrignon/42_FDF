/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:53:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/14 01:21:30 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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