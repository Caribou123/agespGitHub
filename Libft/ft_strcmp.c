/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:45:55 by agesp             #+#    #+#             */
/*   Updated: 2018/11/08 15:45:48 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int save_s1;

	i = 0;
	save_s1 = 0;
	if (s1[i] && !s2[i])
		return (1);
	if (!s1[i] && s2[i])
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s2, ++s1;
	}
	return (*s1 - *s2);
}
