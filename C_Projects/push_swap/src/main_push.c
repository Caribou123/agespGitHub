/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:58:07 by agesp             #+#    #+#             */
/*   Updated: 2019/02/06 16:27:48 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_solo(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	return (1);
}

static char	**create_tab_2(int ac, char **av)
{
	char	**tab;
	char	*save;

	if (ac == 2 && is_solo(av[1]))
		return (NULL);
	if (ac == 2 && ft_strcmp(av[1], "-v"))
	{
		save = ft_itoa(ft_atoi(av[1]));
		if (ft_strcmp(av[1], save))
			tab = ft_strsplit(av[1], ' ');
		else
			tab = NULL;
		save ? free(save) : do_nothing();
	}
	else
		tab = NULL;
	return (tab);
}

int			main(int ac, char **av)
{
	t_push	*a;
	t_push	*b;
	char	**tab;

	tab = create_tab_2(ac, av);
	if (tab)
		ac = len_tab(tab);
	if (ac > 1)
	{
		if ((!tab && is_input_ok((int)ac, av))
				|| (tab && is_input_ok(ac, tab)))
		{
			a = fill_pile(ac, tab ? tab : av, 1);
			b = fill_pile(ac, tab ? tab : av, 0);
			nquick_sort(a, b);
			free_list(a);
			free_list(b);
		}
		else
			ft_printf("Error\n");
	}
	tab ? free_tab(tab) : do_nothing();
	return (0);
}
