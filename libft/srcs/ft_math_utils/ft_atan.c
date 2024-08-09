/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:51:46 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 01:07:37 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

#define CORDIC_ITER 16
#define CORDIC_GAIN 0.607252935008881

/*
 * Cordic arctan.
 */
double ft_atan(double x)
{
	double z = 0.0;
	double x_val = 1.0;
	double y_val = 0.0;
	double angle = M_PI / 4.0;
	int i;
	

	i = -1;
	while (++i < CORDIC_ITER)
	{
		if (x < 0)
		{
			x += y_val;
			y_val -= x;
			z -= angle;
		}
		else
		{
			x -= y_val;
			y_val += x;
			z += angle;
		}
		x_val *= 0.5;
		y_val *= 0.5;
		angle *= 0.5;
	}
	return (z * CORDIC_GAIN);
}
