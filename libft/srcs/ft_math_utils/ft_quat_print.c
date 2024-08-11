/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:52:12 by myeow             #+#    #+#             */
/*   Updated: 2024/08/11 18:14:32 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_fd(char *s, int fd);

void	ft_quat_print(t_quat *q)
{
	ft_putstr_fd("[w: ", 1);
	ft_putdbl_fd(q->w, 1);
	ft_putstr_fd(", x: ", 1);
	ft_putdbl_fd(q->v.x, 1);
	ft_putstr_fd(", y: ", 1);
	ft_putdbl_fd(q->v.y, 1);
	ft_putstr_fd(", z: ", 1);
	ft_putdbl_fd(q->v.z, 1);
	ft_putstr_fd("]\n", 1);
}