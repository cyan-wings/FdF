/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_perspective.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:39:25 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 00:32:28 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_projection_perspective(t_point *p, double focal_len,
		double cam_dist)
{
	double	dist_from_focal;
	double	factor;

	dist_from_focal = cam_dist - p->t.z + focal_len;
	factor = focal_len / dist_from_focal;
	p->v = (t_vec2){.x = (p->t.x * factor) + 0.5,
		.y = (p->t.y * factor) + 0.5};
}
