/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:48:11 by myeow             #+#    #+#             */
/*   Updated: 2024/08/15 01:15:00 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "ft_math_utils.h"

# if defined(__APPLE__)
#  include "keys_macos.h"
# else
#  include "keys_linux.h"
# endif

typedef struct s_mlx_vars
{
	int		x_res;
	int		y_res;
	void	*mlx;
	void	*mlx_win;
}			t_mlx_vars;

/*
 * This struct represents a point on the map.
 * @vars
 * 		z: The height of the point.
 * 		color: The color of the point.
 * 		r_color: The color of the point beside on the right.
 * 		b_color: The color of the point below it.
 */
typedef struct s_point
{
	int	z;
	int	color;
	int	r_color;
	int	b_color;
}		t_point;

typedef struct s_map
{
	t_point	***map;
	int		width;
	int		length;
	int		z_max;
	int		z_min;
}			t_map;

/* 
 * Struct information is retrieved from mlx_get_data_addr function.
 * @vars:
 * 		pxl_size: pixel bit size.
 * 		line_len: Number of pixels in the image horizontally.
 */
typedef struct s_image_data
{
	char	*addr;
	int		pxl_bit_size;
	int		line_len;
	int		endian;
	int		x_origin_offset;
	int		y_origin_offset;
	int		curr_color;
}			t_img;

typedef struct s_draw_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	int		steep;
	double	gradient;
}			t_draw_line;

typedef struct s_fdf
{
	t_map	*map;
	t_img	*img;
	char	*addr;
	t_quat	orientation;
}			t_fdf;

void	fdf_error_exit(char *err_msg, int exit_status);
int		fdf_parse(const char *filename, t_map *map);

//MAP
void	fdf_map_init(const char *filename, t_map *map);
void	fdf_map_print(t_map *map);

//HOOKS
int		fdf_hooks_key(int code, t_mlx_vars *vars);
int		fdf_hooks_exit(t_mlx_vars *vars);

//DRAW
void	fdf_draw_line(t_img *img, t_vec2 *a, t_vec2 *b);
void	fdf_draw_image(t_mlx_vars *vars, t_img *data);

#endif
