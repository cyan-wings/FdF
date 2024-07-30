/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:52:34 by myeow             #+#    #+#             */
/*   Updated: 2024/07/31 00:46:00 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

static void	plot(t_data *data, int x, int y, double intensity)
{
	t_color	color;
	
	printf("x: %d, y: %d\n", x, y);
	color = (t_color) {.t_trgb.r = 255, \
		.t_trgb.t = (unsigned char)(255 * intensity)};
	mlx_plot_pixel(data, x, y, color);
}

static double	first_endpoint_plot(t_data *data, t_draw_line *info)
{
	double	x;
	double	y;
	double	x_gap;

	x = ft_round(info->x0);
	y = info->y0 + info->gradient * (x - info->x0);
	x_gap = ft_rev_fractional(info->x0 + 0.5);
	info->x0 = (int)x;
	info->y0 = (int)y;
	if (info->steep)
	{
		plot(data, info->y0, info->x0, ft_rev_fractional(y) * x_gap);
		plot(data, info->y0 + 1, info->x0, ft_fractional(y) * x_gap);
	}
	else
	{
		plot(data, info->x0, info->y0, ft_rev_fractional(y) * x_gap);
		plot(data, info->x0, info->y0 + 1, ft_fractional(y) * x_gap);
	}
	return (y + info->gradient);
}

static void	second_endpoint_plot(t_data *data, t_draw_line *info)
{
	double	x;
	double	y;
	double	x_gap;

	x = ft_round(info->x1);
	y = info->y1 + info->gradient * (x - info->x1);
	x_gap = ft_fractional(info->x1 + 0.5);
	info->x1 = (int)x;
	info->y1 = (int)y;
	if (info->steep)
	{
		plot(data, info->y1, info->x1, ft_rev_fractional(y) * x_gap);
		plot(data, info->y1 + 1, info->x1, ft_fractional(y) * x_gap);
	}
	else
	{
		plot(data, info->x1, info->y1, ft_rev_fractional(y) * x_gap);
		plot(data, info->x1, info->y1 + 1, ft_fractional(y) * x_gap);
	}
}

static void	FdF_draw_line_helper(t_data *data, t_draw_line *info)
{
	double	intery;
	int		x;

	intery = first_endpoint_plot(data, info);
	second_endpoint_plot(data, info);
	x = info->x0;
	if (info->steep)
	{
		while (++x < info->x1)
		{
			plot(data, (int)intery, x, ft_rev_fractional(intery));
			plot(data, (int)intery + 1, x, ft_fractional(intery));
			intery += info->gradient;
			printf("%f\n", info->gradient);
		}
	}
	else
	{
		while (++x < info->x1)
		{
			plot(data, x, (int)intery, ft_rev_fractional(intery));
			plot(data, x, (int)intery + 1, ft_fractional(intery));
			intery += info->gradient;
		}
	}
}

void	FdF_draw_line(t_data *data, t_vec2 *a, t_vec2 *b)
{
	t_draw_line	info;

	info.x0 = a->x;
	info.y0 = a->y;
	info.x1 = b->x;
	info.y1 = b->y;
	info.steep = ft_abs(info.y1 - info.y0) > ft_abs(info.x1 - info.x0);
	if (info.steep)
	{
		ft_swap(&info.x0, &info.y0);
		ft_swap(&info.x1, &info.y1);
	}
	if (info.x0 > info.x1)
	{
		ft_swap(&info.x0, &info.x1);
		ft_swap(&info.y0, &info.y1);
	}
	info.gradient = (info.y1 - info.y0) / (info.x1 - info.x0);
	FdF_draw_line_helper(data, &info);
}
