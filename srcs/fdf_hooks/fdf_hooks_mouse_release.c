/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_mouse_release.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:42:41 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 00:43:24 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_macos.h"
#include "fdf.h"

int	fdf_hooks_mouse_release(int code, t_mlx_vars *vars)
{
	(void)x;
	(void)y;
	if (keycode == M_CLK_L)
		vars->fdf->hold.left_m = false;
	if (keycode == M_CLK_R)
		vars->fdf->hold.right_m = false;
	if (keycode == M_CLK_M)
		vars->fdf->hold.middle_m = false;
	return (0);
}
