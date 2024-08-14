/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:41:33 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 01:17:48 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	fdf_draw_menu(t_mlx_vars *vars)
{
	char	*str;
	char	*val;

	mlx_string_put(vars->mlx, vars->mlx_win, 100, vars->y_res - 200, 0xffbbbbbb,
			"FDF");
	val = ft_itoa(vars->x_res);
	str = ft_strjoin("x_res: ", val);
	mlx_string_put(vars->mlx, vars->mlx_win, 100, vars->y_res - 180, 0xffbbbbbb, str);
	free(val);
	free(str);
}
