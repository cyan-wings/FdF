/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_translate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:27:45 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 21:19:38 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * v should be a const.
 */
void	fdf_projection_translate(t_vec3 *v, double x, double y, double z)
{
	v->x += x;
	v->y += y;
	v->z += z;
}
