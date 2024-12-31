/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_key_release.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:08:24 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 16:56:09 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include "keys_macos.h"
#elif defined(__linux__)
# include "keys_linux.h"
#else
# error "Test"
#endif
#include "fdf.h"

void	fdf_animation_isometric(t_proj *pj);

void	fdf_animation_perspective(t_proj *pj);

void	fdf_animation_top(t_proj *pj);

int	fdf_hooks_key_release(int code, t_mlx_vars *vars)
{
	t_proj	*pj;

	pj = vars->image->proj;
	if (code == KEY_ESC)
		return (fdf_hooks_exit(vars));
	if (code == KEY_I)
		fdf_animation_isometric(pj);
	if (code == KEY_P)
		fdf_animation_perspective(pj);
	if (code == KEY_O)
		fdf_animation_top(pj);
	fdf_draw_image(vars);
	return (0);
}
