/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:09:47 by myeow             #+#    #+#             */
/*   Updated: 2024/08/05 23:36:15 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	is_valid_color(char *temp)
{
	int		i;

	if (!temp)
		return (1);
	if (temp[0] != '0' && temp[1] != 'x')
		return (0);
	i = 1;
	while (temp[++i])
		if (!ft_ishex(temp[i]))
			return (0);
	if (i != 4 && i != 6 && i != 8)
		return (0);
	return (!temp[i]);
}

static int	is_valid_number(char *str)
{
	char	*temp;
	int		i;

	if (!str || !*str)
		return (0);
	temp = 0;
	temp = ft_strtok(str, ",");
	i = 0;
	if (temp[i] == '+')
		++temp;
	else if (temp[i] == '-')
		++i;
	--i;
	while (temp[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	temp = ft_itoa(ft_atoi(str));
	if (ft_strcmp(temp, str))
	{
		ft_memdel((void **) &temp);
		return (0);
	}
	ft_memdel((void **) &temp);
	temp = ft_strtok(0, ",");
	return (is_valid_color(temp));
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
			if (!is_valid_number(temp))
				return (0);
			++i;
			temp = ft_strtok_r(0, " \n", &save_ptr);
		}
		if (i != row)
			return (0);
		++*col;
		*line = get_next_line(fd);
	}
	return (1);
}

static void	get_row_col(int fd, int *row, int *col)
{
	char	*line;
	char	*save_ptr;
	char	*temp;

	line = 0;
	line = get_next_line(fd);
	if (!line)
		return ;
	save_ptr = 0;
	temp = ft_strtok_r(line, " \n", &save_ptr);
	while (temp)
	{
		if (!is_valid_number(temp))
		{
			*row = 0;
			return ;
		}
		++*row;
		temp = ft_strtok_r(0, " \n", &save_ptr);
	}
	++*col;
	if (!get_row_col_helper(fd, &line, *row, col))
		*row = 0;
	ft_memdel((void **) &line);
}

int	fdf_parse(const char *filename)
{
	int	fd;
	int	row;
	int	col;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	row = 0;
	col = 0;
	get_row_col(fd, &row, &col);
	printf("row: %d, col: %d\n", row, col);
	if (!row)
		return (0);
	return (1);
}
