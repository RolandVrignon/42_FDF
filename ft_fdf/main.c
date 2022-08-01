/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:53:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/08/01 16:16:14 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void print_lines(t_line *lines)
// {
//     int i;
//     t_column *column;
//     t_pixel  *pixel;
//     i = 0;
//     while(lines)
//     {
//         column = lines->column;
//         while(column)
//         {
//             pixel = column->pixel;
//             printf("{%.2f,%.2f}  ", pixel->u, pixel->v);
//             column = column->next;
//             i++;
//         }
//         ft_printf("\n");
//         lines = lines->next;
//     }
// }

static int	double_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	check_lines(char *str, char **line, int len, int fd)
{
	int	new_len;

	while (str)
	{
		new_len = double_len(line);
		free_double(line);
		free(str);
		if (new_len != len)
		{	
			close(fd);
			return (0);
		}
		str = get_next_line(fd);
		line = ft_split(str, ' ');
	}
	return (1);
}

static int	check_map(char *map)
{
	int		fd;
	char	*str;
	char	**line;
	int		len;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	if (!str)
		return (0);
	line = ft_split(str, ' ');
	len = double_len(line);
	if (!check_lines(str, line, len, fd))
		return (0);
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_line	*lines;

	(void)av;
	if (ac == 2)
	{
		if (!check_map(av[1]))
		{
			ft_printf("Map error\n");
			return (0);
		}
		lines = create_coordonates(av[1]);
		if (!lines)
		{
			ft_printf("Map error\n");
			return (0);
		}
		mlx_main(lines);
		free_lines(lines);
	}
	else
		ft_printf("Too few or to many arguments\n");
	return (0);
}
