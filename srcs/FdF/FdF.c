/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:23 by myeow             #+#    #+#             */
/*   Updated: 2024/08/03 22:31:38 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <math.h>

static void	mark_origin(t_data *data)
{
	t_color	color;

	color = (t_color){.t_trgb.r = 255};
	mlx_plot_pixel(data, 0, 0, color);
}

static void	test_line(t_data *data)
{
	int		i;
	int		r;
	double	rr;
	t_vec2	a;
	t_vec2	b;

	data->curr_color = (t_color){.t_trgb.r = 255};
	i = 0;
	r = 300;
	a = (t_vec2){.x = 0, .y = 0};
	while (i <= 360)
	{
		rr = (double)i * M_PI / 180;
		b = (t_vec2){.x = r * -cos(rr), .y = r * -sin(rr)};
		fdf_draw_line(data, &a, &b);
		i += 1;
	}
}
/*
	t_vec2	c = (t_vec2) {-600, -600};
	t_vec2	d = (t_vec2) {600, 600};
	data->curr_color = (t_color) {.t_trgb.b = 255};

	FdF_draw_line(data, &d, &c);

	t_vec2	e = (t_vec2) {600, -600};
	t_vec2	f = (t_vec2) {-600, 600};
	data->curr_color = (t_color) {.t_trgb.b = 255};
	FdF_draw_line(data, &e, &f);
*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.x_res = 1920;
	img.y_res = 1080;
	img.x_origin_offset = img.x_res / 2;
	img.y_origin_offset = img.y_res / 2;
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
