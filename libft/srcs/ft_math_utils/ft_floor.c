/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:49:06 by myeow             #+#    #+#             */
/*   Updated: 2024/07/30 20:53:25 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_floor(double d)
{
	int	i;

	i = (int) d;
	if (d < 0 && d != i)
		--i;
	return ((double) i);
}