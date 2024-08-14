/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:16:26 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 00:24:20 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "libft.h"
#include "limits.h"
#include "get_next_line.h"

static void	alloc_map_helper(t_map *map, t_point ***grid)
{
	int		l;
	t_point	**row;
	int		w;
	t_point	*p;

	l = -1;
	while (++l < map->length)
	{
		row = 0;
		row = (t_point **)ft_calloc(map->width + 1, sizeof(t_point *));
		if (!row)
			fdf_error_exit("Malloc grid width fail.", 1);
		w = -1;
		while (++w < map->width)
		{
			p = (t_point *)ft_memalloc(sizeof(t_point));
			if (!p)
				fdf_error_exit("Malloc point fail.", 1);
			row[w] = p;
		}
		grid[l] = row;
	}
}

static void	alloc_map(t_map *map)
{
	t_point	***grid;

	grid = 0;
	grid = (t_point ***)ft_calloc(map->length + 1, sizeof(t_point **));
	if (!grid)
		fdf_error_exit("Malloc grid fail.", 1);
	alloc_map_helper(map, grid);
	map->map = grid;
}

static void	process_color(char *hex_code, t_point *point)
{
	char	*buf;
	int		i;

	if (!hex_code)
		return ;
	++hex_code;
	++hex_code;
	buf = 0;
	buf = (char *)ft_calloc(6 + 1, sizeof(char));
	i = -1;
	while (++i < 6)
	{
		if (*hex_code)
			buf[i] = ft_toupper(*hex_code++);
		else
			buf[i] = '0';
	}
	point->color = ft_atoi_base(buf, "0123456789ABCDEF");
	ft_memdel((void **) &buf);
}

static void	fdf_init_map_helper(t_map *map, char *line, int *l)
{
	char	*save_ptr;
	char	*temp;
	int		w;
	int		z_value;

	save_ptr = 0;
	temp = 0;
	temp = ft_strtok_r(line, " \n", &save_ptr);
	w = 0;
	while (temp)
	{
		z_value = ft_atoi(ft_strtok(temp, ","));
		map->map[*l][w]->z = z_value;
		if (z_value > map->z_max)
			map->z_max = z_value;
		if (z_value < map->z_min)
			map->z_min = z_value;
		process_color(ft_strtok(0, ","), (map->map)[*l][w]);
		++w;
		temp = ft_strtok_r(0, " \n", &save_ptr);
	}
}

void	fdf_map_init_rb_color(t_map *map);

#include <stdio.h>
void	fdf_map_init(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		l;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error_exit("Cannot open file when initiating map", 1);
	alloc_map(map);
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	line = 0;
	line = get_next_line(fd);
	l = 0;
	while (line)
	{
		fdf_init_map_helper(map, line, &l);
		line = get_next_line(fd);
		++l;
	}
	close(fd);
	ft_memdel((void **) &line);
	fdf_map_init_rb_color(map);
	printf("Success in initialising map: %s\n", filename);
	printf("Min Z: %d, Max Z: %d\n", map->z_min, map->z_max);
}
