/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:54 by myeow             #+#    #+#             */
/*   Updated: 2024/08/13 21:01:35 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_hooks_key(int code, t_mlx_vars *vars)
{
	if (code == KEY_ESC)
		return (fdf_hooks_exit(vars));
	return (0);
}
