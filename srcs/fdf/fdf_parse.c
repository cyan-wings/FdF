/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:09:47 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 14:16:53 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int	fdf_parse_is_valid_value(char *str);

static int	free_line_return_zero(char **line)
{
	ft_memdel((void **)line);
	return (0);
}

static int	get_row_col_helper(int fd, char **line, int row, int *col)
{
	char	*temp;
	int		i;
	char	*save_ptr;

	temp = 0;
	*line = get_next_line(fd);
	while (*line)
	{
		i = 0;
		save_ptr = 0;
		temp = ft_strtok_r(*line, " \n", &save_ptr);
		while (temp)
		{
			if (!fdf_parse_is_valid_value(temp))
				return (free_line_return_zero(line));
			++i;
			temp = ft_strtok_r(0, " \n", &save_ptr);
		}
		ft_memdel((void **)line);
		if (i != row)
			return (0);
		++*col;
		*line = get_next_line(fd);
	}
	return (1);
}

static int	get_row_col(int fd, int *row, int *col)
{
	char	*line;
	char	*save_ptr;
	char	*temp;

	line = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	save_ptr = 0;
	temp = ft_strtok_r(line, " \n", &save_ptr);
	while (temp)
	{
		if (!fdf_parse_is_valid_value(temp))
			return (free_line_return_zero(&line));
		++*row;
		temp = ft_strtok_r(0, " \n", &save_ptr);
	}
	ft_memdel((void **)&line);
	++*col;
	return (get_row_col_helper(fd, &line, *row, col));
}

int	fdf_parse(const char *filename, t_map *map)
{
	int	fd;
	int	status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	status = get_row_col(fd, &map->width, &map->length);
	close(fd);
	if (!status)
		return (0);
	return (1);
}
