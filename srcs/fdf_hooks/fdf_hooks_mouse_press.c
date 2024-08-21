/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_mouse_press.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:40:23 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 00:42:26 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_macos.h"
#include "fdf.h"

int	fdf_hooks_mouse_press(int code, t_mlx_vars *vars)
{
	vars->fdf->hold.prev_x = x;
	vars->fdf->hold.prev_y = y;
	if (keycode == M_CLK_L)
		vars->fdf->hold.left_m = true;
	if (keycode == M_CLK_R)
		vars->fdf->hold.right_m = true;
	if (keycode == M_CLK_M)
		vars->fdf->hold.middle_m = true;
	if (keycode == M_SCR_U)
		z_rot(vars, -0.1);
	if (keycode == M_SCR_D)
		z_rot(vars, 0.1);
	return (0);
}
