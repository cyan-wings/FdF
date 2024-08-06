/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:53:57 by myeow             #+#    #+#             */
/*   Updated: 2024/08/06 21:07:11 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	alloc_map_helper(t_map *map, t_point ***grid)
{
	int		l;
	t_point	**row;
	int		w;
	t_point	*p;

	l = -1;
	while (++l < map->length + 1)
	{
		row = 0;
		row = (t_point **)ft_calloc(map->width + 1, sizeof(t_point *));
		if (!row)
			fdf_error("Malloc grid fail.", 1);
		w = -1;
		while (++w < map->width + 1)
		{
			p = (t_point *)ft_memalloc(sizeof(t_point));
			if (!p)
				fdf_error("Malloc point fail.", 1);
			*row++ = p;
		}
		*grid++ = row;
	}
}

static void	alloc_map(t_map *map)
{
	t_point	***grid;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error("File failed to open.", 1);
	grid = 0;
	grid = (t_point ***)ft_calloc(map->length + 1, sizeof(t_point **));
	if (!grid)
		fdf_error("Malloc grid fail.", 1);
	alloc_map_helper(map, grid);
	map->map = grid;
}

void	process_color(char *hex_code, t_point **point_color)
{
	++hex_code;
	++hex_code;
}

void	fdf_init_map_helper(t_map *map, char *line, int *l)
{
	char	*save_ptr;
	char	*temp;
	int		w;
	int		z;

	save_ptr = 0;
	temp = 0;
	temp = ft_strtok_r(line, "\n", &save_ptr);
	w = 0;
	while (temp)
	{
		((map->map)[*l][w])->z = ft_atoi(ft_strtok(temp, ","));
		process_color(ft_strtok(0, ","), (map->map)[*l][w]);
		++w;
	}
}


void	fdf_init_map(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*save_ptr;
	int		l;
	int		w;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error("Cannot open file.");
	alloc_map(map);
	line = 0;
	line = get_next_line(fd);
	l = 0;
	while (line)
	{
		fdf_init_map_helper(line, &l);
		line = get_next_line(fd);
		++l;
	}
}
