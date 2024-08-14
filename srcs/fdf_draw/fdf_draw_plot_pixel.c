/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_plot_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:04:34 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 01:00:03 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * If the resolution value is odd, the rightmost column of pixels (x) and 
 * bottommost row of pixels (y) is treated as a buffer.
 * This is designed this way to reduce checks that can potentially reduce
 * performance.
 */
void	fdf_draw_plot_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= img->x_origin_offset || x < -img->x_origin_offset)
		return ;
	if (y >= img->y_origin_offset || y < -img->y_origin_offset)
		return ;
	x += img->x_origin_offset;
	y = img->y_origin_offset - 1 - y;
	dst = img->addr + (y * img->line_len + x * (img->pxl_bit_size / 8));
	*((unsigned int *) dst) = color;
}
