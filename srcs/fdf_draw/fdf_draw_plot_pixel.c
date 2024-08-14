/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_plot_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:04:34 by myeow             #+#    #+#             */
/*   Updated: 2024/08/14 15:06:52 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * If the resolution value is odd, the rightmost column of pixels (x) and 
 * bottommost row of pixels (y) is treated as a buffer.
 * This is designed this way to reduce checks that can potentially reduce
 * performance.
 */
void	fdf_draw_plot_pixel(t_mlx_vars *vars, int x, int y, t_color color)
{
	char	*dst;

	if (x >= vars->x_origin_offset || x < -vars->x_origin_offset)
		return ;
	if (y >= vars->y_origin_offset || y < -vars->y_origin_offset)
		return ;
	x += vars->x_origin_offset;
	y = vars->y_origin_offset - 1 - y;
	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*((unsigned int *) dst) = color.code;
}
