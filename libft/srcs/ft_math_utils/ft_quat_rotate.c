/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:38:52 by myeow             #+#    #+#             */
/*   Updated: 2024/08/12 18:32:27 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_utils.h"

/*
 * @vars
 * 	sq: squares
 * 	sc: scalars
 * 	p: pairs
 *
 * 	This function rotates the vector v by the quaternion q.
 * 	Quaternion q can be converted to axis-angle to comprehend or test.
 * 	Out is the resulting vector from the rotation.
 */
void	ft_quat_rotate(t_vec3 *v, t_quat *q, t_vec3 *out)
{
	const double	sq[4] = {
		q->w * q->w, q->v.x * q->v.x, q->v.y * q->v.y, q->v.z * q->v.z};
	const double	sc[3] = {
		q->w * q->v.x, q->w * q->v.y, q->w * q->v.z};
	const double	p[3] = {
		q->v.x * q->v.y, q->v.x * q->v.z, q->v.y * q->v.z};

	if (!q || !v || !out)
		return ;
	out->x = (sq[0] + sq[1] - sq[2] - sq[3]) * v->x
		+ 2 * (p[0] - sc[2]) * v->y
		+ 2 * (p[1] + sc[1]) * v->z;
	out->y = (sq[0] - sq[1] + sq[2] - sq[3]) * v->y
		+ 2 * (p[0] + sc[2]) * v->x
		+ 2 * (p[2] - sc[0]) * v->z;
	out->z = (sq[0] - sq[1] - sq[2] + sq[3]) * v->z
		+ 2 * (p[1] - sc[1]) * v->x
		+ 2 * (p[2] + sc[0]) * v->y;
}
