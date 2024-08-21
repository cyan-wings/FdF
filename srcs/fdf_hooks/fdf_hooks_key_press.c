/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:00:20 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 00:33:50 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_macos.h"
#include "fdf.h"

static void	hook_wasd_to_translate(int code, t_mlx_vars *vars)
{
	t_img	*image;

	image = vars->image;
	if (code == KEY_A)
		fdf_projection_translate(&image->map_pos, -10, 0, 0);
	if (code == KEY_D)
		fdf_projection_translate(&image->map_pos, 10, 0, 0);
	if (code == KEY_W)
		fdf_projection_translate(&image->map_pos, 0, 10, 0);
	if (code == KEY_S)
		fdf_projection_translate(&image->map_pos, 0, -10, 0);
	fdf_draw_image(vars);
}

static void	hook_arrow_keys_to_scale(int code, t_mlx_vars *vars)
{
	t_img	*image;
	t_map	*map;

	image = vars->image;
	map = image->map;
	if (code == KEY_ARROW_RIGHT)
	{
		image->map_scale *= 1.0 / 0.9;
		map->sq_side_len *= 1.0 / 0.9;
	}
	if (code == KEY_ARROW_LEFT)
	{
		image->map_scale *= 0.9;
		map->sq_side_len *= 0.9;
	}
	if (code == KEY_ARROW_DOWN)
		map->z_scale_val -= 0.1;
	if (code == KEY_ARROW_UP)
		map->z_scale_val += 0.1;
	fdf_draw_image(vars);
}

int	fdf_hooks_key_press(int code, t_mlx_vars *vars)
{
	hook_wasd_to_translate(code, vars);
	hook_arrow_keys_to_scale(code, vars);
	return (0);
}
