/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:23:50 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 00:42:46 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

double	fast_inverse_sqrt(double number)
{
	double			x2;
	double			y;
	const double	threehalfs = 1.5;
	t_conv			conv;

	x2 = number * 0.5;
	y = number;
	conv.d = y;
	conv.i = 0x5fe6eb50c7b537a9 - (conv.i >> 1);
	y = conv.d;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

double	ft_sqrt(double x)
{
	return (1.0 / fast_inverse_sqrt(x));
}
