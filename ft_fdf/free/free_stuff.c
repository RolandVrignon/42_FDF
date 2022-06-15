/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:09:58 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/16 01:08:36 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	free_stuff(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	free(str);
	return (1);
}

void	free_column(t_column *column)
{
	t_column	*tmp;
	t_pixel		*pixel;

	if (!column)
		return ;
	while (column)
	{
		pixel = column->pixel;
		tmp = column;
		column = column->next;
		free(pixel);
		free(tmp);
	}
	free(column);
}

void	free_lines(t_line *lines)
{
	t_line	*tmp;

	if (!lines)
		return ;
	while (lines->next != NULL)
	{
		free_column(lines->column);
		tmp = lines;
		lines = lines->next;
		free(tmp);
	}
	free(lines);
}
