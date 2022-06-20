/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:44:10 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/20 18:07:43 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	fdf_color_degrade_r(int clr_a, int clr_b, int index)
{
	int				r_a;
	int				r_b;
	int				mask;

	mask = 255 << 16;
	r_a = (clr_a & mask) >> 16;
	r_b = (clr_b & mask) >> 16;
	mask = (r_a + ((r_b - r_a) * index / 100)) << 16;
	return (mask);
}

static int	fdf_color_degrade_g(int clr_a, int clr_b, int index)
{
	int				g_a;
	int				g_b;
	int				mask;

	mask = 255 << 8;
	g_a = (clr_a & mask) >> 8;
	g_b = (clr_b & mask) >> 8;
	mask = (g_a + ((g_b - g_a) * index / 100)) << 8;
	return (mask);
}

static int	fdf_color_degrade_b(int clr_a, int clr_b, int index)
{
	int				b_a;
	int				b_b;
	int				mask;

	mask = 255;
	b_a = clr_a & mask;
	b_b = clr_b & mask;
	return (b_a + ((b_b - b_a) * index / 100));
}

int	c(int clr_a, int clr_b, int index)
{
	int				r;
	int				g;
	int				b;
	int				color;

	if (index <= 0 || index >= 100)
	{
		if (index < 100)
			return (clr_a);
		else
			return (clr_b);
	}	
	r = fdf_color_degrade_r(clr_a, clr_b, index);
	g = fdf_color_degrade_g(clr_a, clr_b, index);
	b = fdf_color_degrade_b(clr_a, clr_b, index);
	color = (r | g) | b;
	return (color);
}

int	atoi_base(char *str)
{
	long int	i;
	double		positif;
	long double	nb;

	i = 0;
	nb = 0;
	positif = 1;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-')
		positif = positif * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'A' && str[i] <= 'F') || str[i] == 'x')
	{
		nb = nb * 16 + (str[i] - '0');
		i++;
	}
	return (nb * positif);
}
