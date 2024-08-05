/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:56:14 by myeow             #+#    #+#             */
/*   Updated: 2024/08/05 23:37:38 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_floor(double d);

double	ft_ceil(double d);

double	ft_round(double d)
{
	double	i;
	double	f;

	i = ft_floor(d);
	f = d - i;
	if (f >= 0.5)
		return (ft_ceil(d));
	return (ft_floor(d));
}
