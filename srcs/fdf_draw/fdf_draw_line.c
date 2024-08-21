/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:52:34 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 17:22:18 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * May want to pass in some global struct in the future.
 */
static void	init_color(t_draw_line *info, t_point *a, t_point *b,
		int default_color)
{
	info->color0 = a->color;
	info->color1 = b->color;
	if (!info->color0)
		info->color0 = default_color;
	if (!info->color1)
		info->color1 = default_color;
}

static void	init_draw_line(t_draw_line *info, t_point *a, t_point *b)
{
	info->x0 = a->v.x;
	info->y0 = a->v.y;
	info->x1 = b->v.x;
	info->y1 = b->v.y;
	info->steep = ft_abs(info->y1 - info->y0) >= ft_abs(info->x1 - info->x0);
	if (info->steep)
	{
		ft_swap(&info->x0, &info->y0);
		ft_swap(&info->x1, &info->y1);
	}
	if (info->x0 > info->x1)
	{
		ft_swap(&info->x0, &info->x1);
		ft_swap(&info->y0, &info->y1);
	}
	info->dx = info->x1 - info->x0;
	info->dy = info->y1 - info->y0;
	if (!info->dx)
		info->gradient = 1;
	else
		info->gradient = info->dy / info->dx;
}

void	fdf_draw_plot_pixel(t_draw_line *info, int x, int y, double intensity);

static double	first_endpoint_plot(t_draw_line *info)
{
	double	x;
	double	y;
	double	x_gap;

	x = ft_round(info->x0);
	y = info->y0 + info->gradient * (x - info->x0);
	x_gap = ft_rev_fractional(info->x0 + 0.5);
	info->x0 = (int)x;
	info->y0 = (int)y;
	info->color_temp = info->color0;
	if (info->steep)
	{
		fdf_draw_plot_pixel(info, info->y0, info->x0,
				ft_rev_fractional(y) * x_gap);
		fdf_draw_plot_pixel(info, info->y0 + 1, info->x0,
				ft_fractional(y) * x_gap);
	}
	else
	{
		fdf_draw_plot_pixel(info, info->x0, info->y0,
				ft_rev_fractional(y) * x_gap);
		fdf_draw_plot_pixel(info, info->x0, info->y0 + 1,
				ft_fractional(y) * x_gap);
	}
	return (y + info->gradient);
}

static void	second_endpoint_plot(t_draw_line *info)
{
	double	x;
	double	y;
	double	x_gap;

	x = ft_round(info->x1);
	y = info->y1 + info->gradient * (x - info->x1);
	x_gap = ft_fractional(info->x1 + 0.5);
	info->x1 = (int)x;
	info->y1 = (int)y;
	info->color_temp = info->color1;
	if (info->steep)
	{
		fdf_draw_plot_pixel(info, info->y1, info->x1,
				ft_rev_fractional(y) * x_gap);
		fdf_draw_plot_pixel(info, info->y1 + 1, info->x1,
				ft_fractional(y) * x_gap);
	}
	else
	{
		fdf_draw_plot_pixel(info, info->x1, info->y1,
				ft_rev_fractional(y) * x_gap);
		fdf_draw_plot_pixel(info, info->x1, info->y1 + 1,
				ft_fractional(y) * x_gap);
	}
}

void	fdf_draw_line_helper(t_draw_line *info, double intery);

#include <stdio.h>
void	fdf_draw_line(t_img *img, t_point *a, t_point *b)
{
	t_draw_line	info;
	int			default_color;
	double		intery;

	info = (t_draw_line){0};
	info.image_data = img;
	default_color = 0xFF0000;
	init_color(&info, a, b, default_color);
	init_draw_line(&info, a, b);
	intery = first_endpoint_plot(&info);
	second_endpoint_plot(&info);
	fdf_draw_line_helper(&info, intery);
}
