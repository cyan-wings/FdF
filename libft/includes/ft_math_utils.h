/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:02:38 by myeow             #+#    #+#             */
/*   Updated: 2024/07/30 23:06:56 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_UTILS_H
# define FT_MATH_UTILS_H

typedef struct s_vec_2d
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec_3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

double	ft_abs(double d);
void	ft_swap(double *a, double *b);
double	ft_floor(double d);
double	ft_ceil(double d);
double	ft_round(double d);
double	ft_fractional(double d);
double	ft_rev_fractional(double d);

#endif
