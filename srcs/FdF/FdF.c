/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:23 by myeow             #+#    #+#             */
/*   Updated: 2024/07/31 00:33:05 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	mark_origin(t_data *data)
{
	t_color	color;

	color = (t_color) {.t_trgb.r = (unsigned char)255};
	mlx_plot_pixel(data, 1930, 0, color);
}

static void	test_line(t_data *data)
{
	t_vec2	a;
	t_vec2	b;

	a.x = 100;
	a.y = 25;

	b.x = 300;
	b.y = 300;
	FdF_draw_line(data, &a, &b);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.x_res = 1920;
	img.y_res = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.x_res, img.y_res, "Hello World!");
	img.img = mlx_new_image(mlx, img.x_res, img.y_res);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mark_origin(&img);
	test_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
