/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:19:12 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 16:51:32 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	print_point_info(t_point *point)
{
	ft_putchar_fd('[', 1);
	ft_putnbr_fd(point->o.x, 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(point->o.y, 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(point->o.z, 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_base_fd(point->color,
			"0123456789ABCDEF", 1);
	ft_putchar_fd(']', 1);
	ft_putchar_fd(' ', 1);
}

void	fdf_map_print(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
			print_point_info(map->map[i][j]);
		ft_putchar_fd('\n', 1);
	}
}
