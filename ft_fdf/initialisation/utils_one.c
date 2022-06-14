/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:55:53 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/15 01:44:53 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		line_lstadd_back(t_line *lines, t_column *column)
{
	t_line *tmp;
	
	while(lines->next != NULL)
		lines=lines->next;
	tmp = (t_line *)malloc(sizeof(t_line));
	if (!tmp)
		return ;
	tmp->column = column;
	tmp->next = NULL;
	lines->next = tmp;
}

void		column_lstadd_back(t_column *column, t_pixel *pixel)
{
	t_column *tmp;
	
	while(column->next != NULL)
		column=column->next;
	tmp = (t_column *)malloc(sizeof(t_column));
	if (!tmp || !pixel)
		return ;
	tmp->next = NULL;
	tmp->pixel = pixel;
	column->next = tmp;
}

t_column	*column_lstnew(t_pixel *pixel)
{
	t_column	*new;

	new = (t_column *)malloc(sizeof(t_column));
	if (!new || !pixel)
		return (NULL);
	new->pixel = pixel;
	new->next = NULL;
	return (new);
}

t_line		*line_lstnew(t_column *column)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->column = column;
	new->next = NULL;
	return (new);
}

t_pixel 	*create_pixel(int i, int j, char *str)
{
	t_pixel *pixel;

	pixel = (t_pixel *)malloc(sizeof(t_pixel));
	if (!pixel)
		return (NULL);
	pixel->x = i;
	pixel->y = j;
	pixel->z = ft_atoi(str);
	pixel->u = (pixel->x - pixel->z) / sqrt(2);
	pixel->v = (pixel->x + 2 * pixel->y + pixel->z) / sqrt(6);
	return (pixel);
}

t_line		*assign_coordonates(char **tab, int i, t_line *lines)
{
	int         j;
	t_column    *column;

	column = column_lstnew(create_pixel(i, 0, tab[0]));
	if (!column)
		return (NULL);
	j = 1;
	while (tab[j] != NULL)
	{
		column_lstadd_back(column, create_pixel(i, j, tab[j]));
		j++;
	}
	if (!lines)
		lines = line_lstnew(column);
	line_lstadd_back(lines, column);
	return (lines);
}

t_line		*create_coordonates(char *str)
{
	int     fd;
	char    *line;
	char    **tab;
	t_line  *lines;
	int     i;

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
			return(NULL);
		lines = assign_coordonates(tab, i, lines);
		free_stuff(tab, line);
		line = get_next_line(fd);
		i++;
	}
	return (lines);
}

