/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:30:16 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 00:04:19 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_utils.h"
#include "ft_math_utils.h"

double	ft_fmod(double x, double y)
{
	double	quotient;
	double	remainder;

	if (y == 0.0)
	{
		ft_putendl_fd("Can't divide by 0", 2);
		return (0);
	}
	if (y < 0)
		y = -y;
	quotient = ft_floor(x / y);
	remainder = x - quotient * y;
	if (remainder < 0 && y > 0)
		remainder += y;
	return (remainder);
}
