/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:48:11 by myeow             #+#    #+#             */
/*   Updated: 2024/08/21 16:23:52 by myeow            ###   ########.fr       */
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
 * 		o: Original vector based on the parsed map.
 * 		color: The color of the point.
 * 		t: Transformed vector (based on operations performed).
 * 		v: Virtual vector to be projected which will be used to draw.
 */
typedef struct s_point
{
	t_vec3			o;
	unsigned int	color;
	t_vec3			t;
	t_vec2			v;
}			t_point;

/*
 * @vars:
 * 		map: The default map after parsing.
 * 		map_v: The virtual map which represents the projection after
 * 			translation, rotation and scaling.
 */
typedef struct s_map
{
	t_point	***map;
	t_point ***map_v;
	int		width;
	int		length;
	int		z_max;
	int		z_min;
	double	sq_side_len;
	t_quat	orientation;
}			t_map;

/* 
 * Struct information is retrieved from mlx_get_data_addr function.
 * @vars:
 * 		pxl_size: pixel bit size.
 * 		line_len: Number of pixels in the image horizontally.
 * 		focal_len: Distance from the camera to the model.
 * 		skip: The larger the skip, the lesser the pixels plotted,
 * 			reducing image quality.
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
	double	focal_len;
	int		skip;
	t_map	*map;
}			t_img;

typedef struct s_draw_line
{
	t_img			*image_data;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	unsigned int	color0;
	unsigned int	color1;
	int				steep;
	double			dx;
	double			dy;
	double			gradient;
	unsigned int	color_temp;
}					t_draw_line;

typedef struct s_projection
{
	t_quat	orientation;
	t_quat	start_o;
	t_quat	end_o;
	t_quat	out_o;
	int		sign;
	double	t;
}			t_proj;

void	fdf_error_exit(char *err_msg, int exit_status);
int		fdf_parse(const char *filename, t_map *map);

//MAP
void	fdf_map_init(const char *filename, t_map *map);
void	fdf_map_print(t_map *map);

//HOOKS
int		fdf_hooks_key(int code, t_mlx_vars *vars);
int		fdf_hooks_exit(t_mlx_vars *vars);

//DRAW
void	fdf_draw_image(t_mlx_vars *vars, t_img *data);

//PROJECTION
void	fdf_projection_perspective(t_point *p, double focal_len, double cam_dist);

#endif
