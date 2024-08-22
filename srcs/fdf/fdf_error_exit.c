/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:13:03 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 17:44:06 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_mem_utils.h"
#include <stdlib.h>
#include "ft_print_utils.h"

static void	free_map(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
			ft_memdel((void **)&map->map[i][j]);
		ft_memdel((void **)&map->map[i]);
	}
	ft_memdel((void **)&map->map);
}

//system("leaks FdF -q");
void	fdf_error_exit(t_map *map, char *err_msg, int exit_status)
{
	if (map)
		free_map(map);
	ft_putendl_fd(err_msg, 2);
	exit(exit_status);
}
