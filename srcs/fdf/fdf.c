/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:23 by myeow             #+#    #+#             */
/*   Updated: 2024/08/07 21:58:12 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <fcntl.h>
#include "ft_print_utils.h"
#include <unistd.h>

/*
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
*/
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
static void	check_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fdf_error_exit("File doesn't exist.", 0);
	close(fd);
}

static void	check_params(int argc, char **argv)
{
	if (argc != 2)
		fdf_error_exit("Usage: ./FdF map.fdf", 0);
	check_file(argv[1]);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_map	map;

	check_params(argc, argv);
	map = (t_map) {0};
	if (!fdf_parse(argv[1], &map))
		fdf_error_exit("Parse error.", 0);
	fdf_init_map(argv[1], &map);
	fdf_print_map(&map);
	printf("Success: %s\n", argv[1]);
	return (0);
	/*
	 *	void	*mlx;
	void	*mlx_win;
	t_data	img;
	img.x_res = 1920;
	img.y_res = 1080;
	img.x_origin_offset = img.x_res / 2;
	img.y_origin_offset = img.y_res / 2;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.x_res, img.y_res, "Hello World!");
	img.img = mlx_new_image(mlx, img.x_res, img.y_res);
	img.addr = mlx_get_data_
		addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mark_origin(&img);
	test_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	*/
}
