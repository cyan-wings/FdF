/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init_rb_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:21:30 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 00:36:36 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_init_rb_color(t_map *map)
{
	int	l;
	int	w;
	int	adjacent_color;

	l = -1;
	while (++l < map->length - 1)
	{
		w = -1;
		while (++w < map->width - 1)
		{
			adjacent_color = map->map[l][w + 1]->color;
			if (adjacent_color)
				map->map[l][w]->r_color = adjacent_color;
			adjacent_color = map->map[l + 1][w]->color;
			if (adjacent_color)
				map->map[l][w]->b_color = adjacent_color;
		}
	}
}
