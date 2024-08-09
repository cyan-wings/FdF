/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:50:28 by myeow             #+#    #+#             */
/*   Updated: 2024/08/10 00:51:34 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_tan(double rad)
{
	return (ft_sin(rad) / ft_cos(rad));
}