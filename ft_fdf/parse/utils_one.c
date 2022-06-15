/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:55:53 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 01:07:56 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	line_lstadd_back(t_line *lines, t_column *column)
{
	t_line	*tmp;

	while (lines->next != NULL)
		lines = lines->next;
	tmp = (t_line *)malloc(sizeof(t_line));
	if (!tmp)
		return ;
	tmp->column = column;
	tmp->next = NULL;
	lines->next = tmp;
}

void	column_lstadd_back(t_column *column, t_pixel *pixel)
{
	t_column	*tmp;

	while (column->next != NULL)
		column = column->next;
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

t_line	*line_lstnew(t_column *column)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->column = column;
	new->next = NULL;
	return (new);
}
