/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:49:58 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 23:50:21 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_projection(t_img *data, t_proj *pj)
{
	t_map	*map;
	int		i;
	int		j;
	t_point	*p;

	map = data->map;
	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
		{
			p = map->map[i][j];
			p->t = p->o;
			p->t.z *= map->z_scale_val;
			if (pj->t < 1)
				ft_quat_rotate(&p->t, &pj->out_o, &p->t);
			else
				ft_quat_rotate(&p->t, &pj->orientation, &p->t);
			fdf_projection_translate(&p->t, data->map_pos.x / data->map_scale,
				data->map_pos.y / data->map_scale,
				data->map_pos.z / data->map_scale);
			fdf_projection_scale(&p->t, data->map_scale);
		}
	}
}
