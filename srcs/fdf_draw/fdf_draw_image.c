/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:41:21 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 00:46:52 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_menu(t_mlx_vars *vars);

void	fdf_draw_image(t_mlx_vars *vars, t_img *data)
{
	void	*img;

	img = mlx_new_image(vars->mlx, vars->x_res, vars->y_res);
	data->addr = mlx_get_data_addr(img, &data->pxl_bit_size, &data->line_len,
			&data->endian);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, 0, 0);
	fdf_draw_menu(vars);
	mlx_destroy_image(vars->mlx, img);
}
