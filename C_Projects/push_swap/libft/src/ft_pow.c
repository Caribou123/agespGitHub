/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:17:40 by agesp             #+#    #+#             */
/*   Updated: 2018/12/19 16:59:01 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double nb, int pow)
{
	if (pow > 1)
	{
		return (nb * ft_pow(nb, pow - 1));
	}
	else if (pow < 0)
	{
		return (1 / ft_pow(nb, -pow));
	}
	if (pow == 1)
		return (nb);
	return (0);
}
