/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_is_valid_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:10:00 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 14:11:50 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	fdf_parse_is_valid_value(char *str)
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
