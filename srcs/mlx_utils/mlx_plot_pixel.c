/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plot_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:34:27 by myeow             #+#    #+#             */
/*   Updated: 2024/08/05 19:09:09 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * If the resolution value is odd, the rightmost column of pixels (x) and 
 * bottommost row of pixels (y) is treated as a buffer.
 * This is designed this way to reduce checks that can potentially reduce
 * performance.
 */
void	mlx_plot_pixel(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	if (x >= data->x_origin_offset || x < -data->x_origin_offset)
		return ;
	if (y >= data->y_origin_offset || y < -data->y_origin_offset)
		return ;
	x += data->x_origin_offset;
	y = data->y_origin_offset - 1 - y;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *) dst) = color.code;
}
