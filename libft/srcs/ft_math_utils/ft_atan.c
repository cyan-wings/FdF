/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:51:46 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 01:26:02 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

/*
 * Rational function approximation.
 */
double	ft_atan(double x)
{
	double	x2;
	double	numerator;
	double	denominator;

	if (x < -1 || x > 1)
	{
		if (x < 0)
			return (-ft_atan(-x));
		return (PI / 2 - ft_atan(1 / x));
	}
	x2 = x * x;
	numerator = x * (1.0 + 0.28 * x2);
	denominator = 1 + 0.64 * x2;
	return (numerator / denominator);
}
