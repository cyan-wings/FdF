/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:41:21 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 17:15:37 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_black_screen(t_mlx_vars *vars, t_img *data)
{
	int		i;
	int		j;
	int		pixel_pos;

	i = -1;
	while (++i < vars->y_res)
	{
		j = -1;
		while (++j < vars->x_res)
		{
			pixel_pos = (i * data->line_len) + (j * data->pxl_bit_size / 8);
			if (data->endian == 1)
				data->addr[pixel_pos] = 0xff;
			else
				data->addr[pixel_pos + 3] = 0xff;
		}
	}
}

void	fdf_draw_wireframe(t_img *data);

void	fdf_draw_menu(t_mlx_vars *vars);

#include <stdio.h>
void	fdf_draw_image(t_mlx_vars *vars, t_img *data)
{
	void	*img;
	t_map	*map;

	img = mlx_new_image(vars->mlx, vars->x_res, vars->y_res);
	data->addr = mlx_get_data_addr(img, &data->pxl_bit_size, &data->line_len,
			&data->endian);
	if (!data->addr)
		return ;
	map = data->map;
	data->skip = 1 / (map->sq_side_len * 0.9) + 1;
	init_black_screen(vars, data);
	fdf_draw_wireframe(data);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, 0, 0);
	fdf_draw_menu(vars);
	mlx_destroy_image(vars->mlx, img);
}
