/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:24:59 by myeow             #+#    #+#             */
/*   Updated: 2024/08/07 21:52:28 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	fdf_print_map(t_map *map)
{
	t_point	***grid;
	int		i;
	int		j;

	grid = map->map;
	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
		{
			ft_putnbr_fd(map->map[i][j]->z, 1);
			ft_putchar_fd(',', 1);
			ft_putnbr_base_fd(map->map[i][j]->color.code, \
					"0123456789ABCDEF", 1);
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('\n', 1);
	}
}
