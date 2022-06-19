/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:10:52 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/19 18:56:50 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_pixel	*create_pixel(double i, double j, char *str)
{
	t_pixel	*pixel;
	double tmp;
	double deg;

	pixel = (t_pixel *)malloc(sizeof(t_pixel));
	if (!pixel)
		return (NULL);
	pixel->x = i;
	pixel->y = j;
	pixel->z = ft_atoi(str);
	pixel->u = (pixel->x - 1.4 * pixel->z ) / sqrt(2);
	pixel->v = (pixel->x + 2 * pixel->y + 1.4 * pixel->z) / sqrt(6);
	pixel->color = WHITE_PIXEL;
	tmp = pixel->u;
	deg = - 50 * M_PI_4 / 35;
	pixel->u = pixel->u + (pixel->u * cos(deg) + pixel->v * sin(deg));
	pixel->v = pixel->v + (-tmp * sin(deg) + pixel->v * cos(deg));
	return (pixel);
}

t_line	*assign_coordonates(char **tab, double i, t_line *lines)
{
	int			j;
	double		k;
	t_column	*column;

	j = 0;
	k = 0;
	column = column_lstnew(create_pixel(i, k, tab[j]));
	if (!column)
		return (NULL);
	while (tab[++j] != NULL)
		column_lstadd_back(column, create_pixel(i, ++k, tab[j]));
	if (!lines)
		lines = line_lstnew(column);
	else
		line_lstadd_back(lines, column);
	return (lines);
}

t_line	*create_coordonates(char *str)
{
	int		fd;
	char	*line;
	char	**tab;
	t_line	*lines;
	double	i;

	lines = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line)
	{
		tab = ft_split(line, ' ');
		if (!tab)
			return (NULL);
		lines = assign_coordonates(tab, i, lines);
		free_stuff(tab, line);
		line = get_next_line(fd);
		i++;
	}
	return (lines);
}

int	line_lstsize(t_line *lst)
{
	int		i;
	t_line	*tmp;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	col_lstsize(t_column *lst)
{
	int			i;
	t_column	*tmp;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
