/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:23 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 00:37:44 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <fcntl.h>
#include "ft_print_utils.h"
#include <unistd.h>

#define RES_WIDTH 1920
#define RES_HEIGHT 1080

/*
 * Checks parameters and also the filename.
 */
static void	check_params(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		fdf_error_exit("Usage: ./FdF map.fdf", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fdf_error_exit("File doesn't exist.", 0);
	close(fd);
}

static void	init_mlx_vars_and_img(t_mlx_vars *vars)
{
	t_img	*image;

	vars->x_res = RES_WIDTH;
	vars->y_res = RES_HEIGHT;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, vars->x_res, \
			vars->y_res, "Fil De Fur");
	image = vars->image;
	image->x_origin_offset = RES_WIDTH / 2;
	image->y_origin_offset = RES_HEIGHT / 2;
	image->focal_len = 300;
	image->map_pos = (t_vec3){0};
	image->map_scale = 1;
}

static void	init_hooks(t_mlx_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, (1L << 0), fdf_hooks_key_press, vars);
	mlx_hook(vars->mlx_win, 3, (1L << 1), fdf_hooks_key_release, vars);
	//mlx_hook(vars->win, 4, (1L << 2), mouse_hook_down, vars);
	//mlx_hook(vars->win, 5, (1L << 3), mouse_hook_up, vars);
	//mlx_hook(vars->win, 6, (1L << 6), mouse_move_hook, vars);
	mlx_hook(vars->mlx_win, 17, (1L << 0), fdf_hooks_exit, vars);
	//mlx_loop_hook(vars->mlx_win, loop_hook, vars);
}

/*
 * Sets to isometric projection
 */
static void	init_projection(t_proj *pj)
{
	t_quat	q;

	ft_quatset_id(&pj->orientation);
	ft_quat_from_zrotation(-PI_4, &q);
	ft_quat_mult(&q, &pj->orientation, &pj->orientation);
	ft_quat_from_xrotation(-PI_4, &q);
	ft_quat_mult(&q, &pj->orientation, &pj->orientation);
	ft_quat_print(&pj->orientation);
	pj->start_o = pj->orientation;
	ft_quatset_id(&pj->end_o);
	ft_quatset_id(&pj->out_o);
	pj->sign = 1;
	pj->t = 1.1;
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_mlx_vars	vars;
	t_img		image;
	t_proj		projection;

	check_params(argc, argv);
	map = (t_map){0};
	if (!fdf_parse(argv[1], &map))
		fdf_error_exit("Parse error.", 0);
	fdf_map_init(argv[1], &map);
	vars = (t_mlx_vars){0};
	image = (t_img){0};
	vars.image = &image;
	init_mlx_vars_and_img(&vars);
	image.map = &map;
	init_projection(&projection);
	image.proj = &projection;
	init_hooks(&vars);
	fdf_draw_image(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
