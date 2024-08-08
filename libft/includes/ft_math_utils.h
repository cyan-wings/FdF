/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:02:38 by myeow             #+#    #+#             */
/*   Updated: 2024/08/09 00:29:00 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_UTILS_H
# define FT_MATH_UTILS_H

# ifndef PI
#  define PI 3.14159265358979323846
# endif

typedef struct s_2d_vector
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_3d_vector
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_quaternion
{
	double	w;
	t_vec3	v;
}			t_quat;

double	ft_abs(double d);
void	ft_swap(double *a, double *b);
double	ft_floor(double d);
double	ft_ceil(double d);
double	ft_round(double d);
double	ft_fractional(double d);
double	ft_rev_fractional(double d);

//QUATERNION_UTILS
t_quat	ft_quatnew(double w, double x, double y, double z);
t_quat	ft_quatnew_id(void);
t_quat	ft_quatdup(t_quat *q);

#endif
