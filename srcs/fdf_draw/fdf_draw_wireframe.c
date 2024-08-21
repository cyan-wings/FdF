/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_wireframe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:45:14 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 23:57:37 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_win_bounds(t_img *data, t_vec2 v, int border)
{
	int	a;

	a = 0;
	a = (v.x >= data->x_origin_offset + border)
		+ (v.x <= -data->x_origin_offset - border)
		+ (v.y >= data->y_origin_offset + border)
		+ (v.y <= -data->y_origin_offset - border);
	return (a);
}

void	fdf_draw_line(t_img *img, t_point *a, t_point *b);

static void	draw_edges(t_img *data, int i, int j, int skip)
{
	t_map		*map;
	t_draw_line	info;

	map = data->map;
	info = (t_draw_line){0};
	if (j + skip < map->width)
	{
		fdf_projection_perspective(map->map[i][j + skip], data->focal_len, 25);
		fdf_draw_line(data, map->map[i][j], map->map[i][j + skip]);
	}
	if (i + skip < map->length)
	{
		fdf_projection_perspective(map->map[i + skip][j], data->focal_len, 25);
		fdf_draw_line(data, map->map[i][j], map->map[i + skip][j]);
	}
}

/*
 * @vars:
 * 		s: Optimisation variable to skip pixels to plot. -1 is to account
 * 			for the loop increment.
 */
void	fdf_draw_wireframe(t_img *data)
{
	int		s;
	int		i;
	int		j;
	t_map	*map;
	t_point	*p;

	s = data->skip - 1;
	i = -1;
	map = data->map;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
		{
			p = map->map[i][j];
			fdf_projection_perspective(p, data->focal_len, 25);
			if (check_win_bounds(data, p->v, map->sq_side_len * 4))
				continue ;
			if (p->t.z > data->focal_len)
				continue ;
			draw_edges(data, i, j, data->skip);
			j += s;
		}
		i += s;
	}
}
