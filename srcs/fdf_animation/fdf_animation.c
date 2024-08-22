/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:58:01 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 17:19:01 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_animation_helper(t_mlx_vars *vars)
{
	t_img	*data;
	t_proj	*pj;

	data = vars->image;
	pj = data->proj;
	if (!ft_quat_isequal(&pj->start_o, &pj->end_o))
		ft_quat_slerp(&pj->start_o, &pj->end_o, pj->t, &pj->out_o);
	ft_quat_normalise(&pj->out_o);
	pj->t += 0.05;
	if (pj->sign == 1 && data->focal_len < 209715200)
		data->focal_len = (data->focal_len - 130) * 2;
	else if (data->focal_len > 130)
		data->focal_len = data->focal_len / 2 + 130;
	fdf_draw_image(vars);
}

int	fdf_animation(t_mlx_vars *vars)
{
	t_proj	*pj;

	pj = vars->image->proj;
	if (vars->cycle_count < vars->cycle_per_frame)
		vars->cycle_count += 1;
	else
		vars->cycle_count = 0;
	if (pj->t < 1 && !vars->cycle_count)
		fdf_animation_helper(vars);
	if (pj->t >= 1.0 && pj->t <= 1.05 && !vars->cycle_count)
	{
		pj->t += 0.10;
		fdf_draw_image(vars);
	}
	return (0);
}
