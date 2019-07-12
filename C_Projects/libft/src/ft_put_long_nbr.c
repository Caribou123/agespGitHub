/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_long_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:03:36 by agesp             #+#    #+#             */
/*   Updated: 2018/12/14 17:08:29 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_long_nbr(long long n)
{
	long long c;

	c = 0;
	if (n == -9223372036854775807)
	{
		ft_putstr("-9223372036854775807");
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_put_long_nbr(-n);
	}
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_put_long_nbr(n / 10);
		}
		c = n % 10;
		ft_putchar(c + '0');
	}
}