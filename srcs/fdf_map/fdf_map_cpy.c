/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:17:04 by myeow             #+#    #+#             */
/*   Updated: 2024/08/20 21:45:55 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_cpy(t_map *map)
{
	int		i;
	int		j;
	t_point	*p1;
	t_point	*p2;

	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
		{
			p1 = map->map[i][j];
			p2 = map->map_v[i][j];
			p2->o = p1->o;
			p2->color = p1->color;
		}
	}
}
