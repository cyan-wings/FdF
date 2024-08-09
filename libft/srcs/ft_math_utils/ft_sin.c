/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:44:16 by myeow             #+#    #+#             */
/*   Updated: 2024/08/09 23:56:32 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

#define P1 0.9999916682
#define P2 -0.1666666667
#define P3 0.0083333333
#define P4 -0.0001984127
#define P5 0.0000027557
#define Q1 1.0
#define Q2 -0.4999999999
#define Q3 0.04166666667
#define Q4 -0.001388888889
#define Q5 0.00002480160

double	ft_sin(double x)
{
	double	x2;
	double	num;
	double	denom;

	x = ft_fmod(x, 2 * PI);
	if (x > PI)
		x -= 2 * PI;
	else if (x < -PI)
		x += 2 * PI;
	x2 = x * x;
	num = x * (P1 + (P2 + (P3 + (P4 + P5 * x2) * x2) * x2) * x2);
	denom = Q1 + (Q2 + (Q3 + (Q4 + Q5 * x2) * x2) * x2) * x2;
	return (num / denom);
}
