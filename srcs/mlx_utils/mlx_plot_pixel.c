/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plot_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:34:27 by myeow             #+#    #+#             */
/*   Updated: 2024/07/31 00:26:22 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
 * TODO: Add checks to x and y so it doesn't segfault
 */
void	mlx_plot_pixel(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	x += (data->x_res / 2) - 1;
	y += (data->y_res / 2) - 1;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *) dst) = color.code;
}
