/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_from_xrotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 01:08:42 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 01:13:01 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

void	ft_quat_from_xrotation(double angle, t_quat *out)
{
	t_vec3	v;

	if (!out)
		return ;
	v = (t_vec3){1, 0, 0};
	ft_quat_from_axis_angle(v, angle, out);
}