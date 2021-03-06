/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:18:27 by agesp             #+#    #+#             */
/*   Updated: 2019/01/24 17:11:44 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_smallest(t_push *p)
{
	int data;

	data = p->data;
	p = get_top_list(p);
	while (p)
	{
		if (p->data < data)
			return (0);
		p = p->next;
	}
	return (1);
}

int		get_direction(t_push *p)
{
	t_push	*s;
	int		i;
	int		j;

	s = copy_pile(p, 1);
	i = 0;
	j = 0;
	s = get_top_list(s);
	while (!is_smallest(s))
	{
		rotate(s, 0, 0);
		i++;
	}
	j = get_list_len(s);
	free_list(s);
	if (i > j / 2)
		return (2);
	return (1);
}

void	sort_left(t_push *a, t_push *b, int print, int *i)
{
	int j;

	a = get_top_list(a);
	j = get_direction(a);
	while (!is_smallest(a) && !is_sorted(a))
	{
		*i += 1;
		j == 2 ? rev_rotate(a, print, 1) : rotate(a, print, 1);
		a = get_top_list(a);
	}
	if (!is_sorted(a))
	{
		*i += 1;
		a = get_top_list(a);
		push(a, b, print, 2);
	}
}

int		get_mediane(t_push *a, t_push *b, int print)
{
	int mediane;
	int i;

	i = 0;
	mediane = get_list_len(a) / 2;
	while (!is_sorted(a))
		sort_left(a, b, print, &i);
	while (!is_full(a) && !is_empty(b))
	{
		i++;
		push(b, a, print, 1);
	}
	a = get_start_list(a);
	while (mediane--)
	{
		i++;
		a = a->next;
	}
	i = a->data;
	return (i);
}
