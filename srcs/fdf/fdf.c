/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:23 by myeow             #+#    #+#             */
/*   Updated: 2024/08/14 18:16:17 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <fcntl.h>
#include "ft_print_utils.h"
#include <unistd.h>

#define RES_WIDTH 1920
#define RES_HEIGHT 1080

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

static void	init_mlx_vars(t_mlx_vars *vars)
{
	vars->x_res = RES_WIDTH;
	vars->y_res = RES_HEIGHT;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, vars->x_res, \
			vars->y_res, "Fil De Fur");
	vars->x_origin_offset = vars->x_res / 2;
	vars->y_origin_offset = vars->y_res / 2;
}

static void	init_hooks(t_mlx_vars *vars)
{
	mlx_hook(vars->mlx_win, 3, (1L << 1), fdf_hooks_key, vars);
	//mlx_hook(vars->win, 4, (1L << 2), mouse_hook_down, vars);
	//mlx_hook(vars->win, 5, (1L << 3), mouse_hook_up, vars);
	//mlx_hook(vars->win, 6, (1L << 6), mouse_move_hook, vars);
	mlx_hook(vars->mlx_win, 17, (1L << 0), fdf_hooks_exit, vars);
	//mlx_loop_hook(vars->mlx_win, loop_hook, vars);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_map		map;
	t_mlx_vars	vars;
	t_img		image;

	check_params(argc, argv);
	map = (t_map) {0};
	if (!fdf_parse(argv[1], &map))
		fdf_error_exit("Parse error.", 0);
	fdf_init_map(argv[1], &map);
	fdf_print_map(&map);
	printf("Success: %s\n", argv[1]);
	vars = (t_mlx_vars) {0};
	init_mlx_vars(&vars);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
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

	t_vec2	c = (t_vec2) {-600, -600};
	t_vec2	d = (t_vec2) {600, 600};
	data->curr_color = (t_color) {.t_trgb.b = 255};

	FdF_draw_line(data, &d, &c);

	t_vec2	e = (t_vec2) {600, -600};
	t_vec2	f = (t_vec2) {-600, 600};
	data->curr_color = (t_color) {.t_trgb.b = 255};
	FdF_draw_line(data, &e, &f);
*/
