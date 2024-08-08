/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quatnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:51:14 by myeow             #+#    #+#             */
/*   Updated: 2024/08/09 00:27:41 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

t_quat	ft_quatnew(double w, double x, double y, double z)
{
	t_quat	q;

	q = (t_quat){.w = w, .v.x = x, .v.y = y, .v.z = z};
	return (q);
}
