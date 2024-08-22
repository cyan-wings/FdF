/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:32:45 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 15:57:34 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_projection_rotate(t_img *img, double angle)
{
	t_quat	q;

	ft_quat_from_zrotation(angle, &q);
	ft_quat_normalise(&q);
	ft_quat_mult(&q, &img->proj->orientation, &img->proj->orientation);
}
