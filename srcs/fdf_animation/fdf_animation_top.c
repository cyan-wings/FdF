/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_animation_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:53:42 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 16:56:19 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_print_utils.h"

void	fdf_animation_top(t_proj *pj)
{
	pj->start_o = pj->orientation;
	ft_quatset_id(&pj->end_o);
	pj->t = 0.0;
	pj->sign = 1;
	pj->orientation = pj->end_o;
	ft_putendl_fd("Top", 1);
}
