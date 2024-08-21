/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_key_release.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:08:24 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 00:37:52 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_macos.h"
#include "fdf.h"

int	fdf_hooks_key_release(int code, t_mlx_vars *vars)
{
	if (code == KEY_ESC)
		return (fdf_hooks_exit(vars));
	return (0);
}
