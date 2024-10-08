/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:43:07 by myeow             #+#    #+#             */
/*   Updated: 2024/08/22 15:05:43 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_hooks_exit(t_mlx_vars *vars)
{
	fdf_error_exit(vars->image->map, "Exiting fdf program!", 0);
	return (1);
}
