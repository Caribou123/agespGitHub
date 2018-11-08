/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:43:03 by agesp             #+#    #+#             */
/*   Updated: 2018/11/08 16:54:40 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,  size_t n)
{
	int i;
	unsigned char *savedst = dst;
	const unsigned char *savesrc = src;

	i = 0;
	if (n) 
	{
		if ((savesrc[i]) == (unsigned char)c)
		{
			return (savedst);
		}
		while (i < n)
		{
			savedst[i] = savesrc[i];
			if ((savesrc[i]) == (unsigned char)c)
				return (&savedst[i + 1]);
			i++;
		}
	}
	return (0);
}
