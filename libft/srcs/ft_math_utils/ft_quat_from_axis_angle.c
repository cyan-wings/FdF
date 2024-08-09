/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_from_axis_angle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 23:15:19 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 00:20:53 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_quat_from_axis_angle(t_vec3 *axis, double angle, t_quat *out)
{
	double	c;

	if (!out)
		return ;
	out->w = ft_cos(angle / 2.0);
	c = ft_sin (angle / 2.0);
	out->v.x = c * axis->x;
	out->v.y = c * axis->y;
	out->v.z = c * axis->z;
}
