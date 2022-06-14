/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:55:53 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/14 20:12:06 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int toIsometric2D(double x, double y,double z, double *u, double*v){
    *u=(x-z)/sqrt(2);
    *v=(x+2*y+z)/sqrt(6);
    return 0;
}