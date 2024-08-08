/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:13:03 by myeow             #+#    #+#             */
/*   Updated: 2024/08/07 18:30:10 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_print_utils.h"

void	fdf_error_exit(char *err_msg, int exit_status)
{
	ft_putendl_fd(err_msg, 2);
	exit(exit_status);
}
