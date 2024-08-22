/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_animation_perspective.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:34:46 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 16:40:05 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_print_utils.h"

void	fdf_animation_perspective(t_proj *pj)
{
	pj->start_o = pj->orientation;
	pj->end_o = pj->orientation;
	pj->out_o = pj->orientation;
	pj->t = 0.0;
	pj->sign = -1;
	pj->orientation = pj->end_o;
}
