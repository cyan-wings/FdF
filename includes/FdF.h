/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:48:11 by myeow             #+#    #+#             */
/*   Updated: 2024/08/06 20:47:04 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "ft_math_utils.h"

typedef union s_color
{
	unsigned int	code;
	struct s_trgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	}					t_trgb;
}					t_color;

typedef struct s_data
{
	int		x_res;
	int		y_res;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_origin_offset;
	int		y_origin_offset;
	t_color	curr_color;
}			t_data;

typedef struct s_draw_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	int		steep;
	double	gradient;
}			t_draw_line;

typedef struct s_point
{
	int		z;
	t_color	color;
}			t_point;

typedef struct s_map
{
	t_point	***map;
	int		width;
	int		length;
	int		z_max;
	int		z_min;
}			t_map;

void	fdf_error(char *err_msg, int exit_status);
void	mlx_plot_pixel(t_data *data, int x, int y, t_color color);
void	fdf_draw_line(t_data *data, t_vec2 *a, t_vec2 *b);
int		fdf_parse(const char *filename);

#endif
