/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:12 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 17:47:10 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
static unsigned int	get_color(t_draw_line *info, double dist, int x,
		double intery)
{
	double	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	
	t = ft_sqrt(ft_power(x - info->x0, 2) + ft_power(intery - info->y0, 2));
	t /= dist;
	r = (info->color0 >> 16) & 0xFF;
	g = (info->color0 >> 8) & 0xFF;
	b = info->color0 & 0xFF;
	r = r + t * (((info->color1 >> 16) & 0xFF) - r);
	g = g + t * (((info->color1 >> 8) & 0xFF) - g);
	b = b + t * (((info->color1) & 0xFF) - b);
	if (info->image_data->endian)
		return ((b << 24) | (g << 16) | (r << 8) | 0);
	else
		return ((0 << 24) | (r << 16) | (g << 8) | b);
}

void	fdf_draw_plot_pixel(t_draw_line *info, int x, int y, double intensity);

static void	plot_between_points(t_draw_line *info, double dist, double intery)
{
	int	x;

	x = info->x0;
	if (info->steep)
	{
		while (++x < info->x1)
		{
			printf("Stupid = %f\n", info->y0);
			info->color_temp = get_color(info, dist, x, intery);
			fdf_draw_plot_pixel(info, (int)intery, x,
					ft_rev_fractional(intery));
			fdf_draw_plot_pixel(info, (int)intery + 1, x,
					ft_fractional(intery));
			intery += info->gradient;
		}
		return ;
	}
	while (++x < info->x1)
	{
		info->color_temp = get_color(info, dist, x, intery);
		fdf_draw_plot_pixel(info, x, (int)intery, ft_rev_fractional(intery));
		fdf_draw_plot_pixel(info, x, (int)intery + 1, ft_fractional(intery));
		intery += info->gradient;
	}
}

void	fdf_draw_line_helper(t_draw_line *info, double intery)
{
	double	dist;

	printf("x0: %f, x1: %f, y0: %f, y1: %f\n", info->x0, info->x1, info->y0, info->y1);
	dist = ft_sqrt(info->dx * info->dx + info->dy * info->dy);
	printf("dist: %f\n", info->dx);
	plot_between_points(info, dist, intery);
}
