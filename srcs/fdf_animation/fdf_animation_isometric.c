/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_animation_isometric.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:18:07 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 16:34:30 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_print_utils.h"

void	fdf_animation_isometric(t_proj *pj)
{
	t_quat	q;

	pj->start_o = pj->orientation;
	ft_quatset_id(&pj->end_o);
	ft_quat_from_zrotation(-PI_4, &q);
	ft_quat_mult(&q, &pj->end_o, &pj->end_o);
	ft_quat_from_xrotation(-PI_4, &q);
	ft_quat_mult(&q, &pj->end_o, &pj->end_o);
	pj->t = 0.0;
	pj->sign = 1;
	pj->orientation = pj->end_o;
	ft_putendl_fd("Isometric", 1);
}
