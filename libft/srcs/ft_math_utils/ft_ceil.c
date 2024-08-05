/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:51:01 by myeow             #+#    #+#             */
/*   Updated: 2024/08/05 23:37:16 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_ceil(double d)
{
	int	i;

	i = (int) d;
	if (d > 0 && d != i)
		++i;
	return ((double) i);
}
