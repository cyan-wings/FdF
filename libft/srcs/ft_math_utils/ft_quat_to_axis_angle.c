/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_to_axis_angle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:14:30 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 00:45:42 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

double	ft_quat_to_axis_angle(t_quat *q, t_vec3 *out)
{
	double	angle;
	double	divider;

	if (!q || !out)
		return (0);
	angle = 2.0 * ft_acos(q->w);
	divider = ft_sqrt(1.0 - q->w * q->w);

    if(divider != 0.0) {
        out.x = q->v.x / divider;
        out.y = q->v.y / divider;
        out.z = q->v.z / divider;
    } else {
        out.x = 1;
        out.y = 0;
        out.z = 0;
    }
    return (angle);
}
