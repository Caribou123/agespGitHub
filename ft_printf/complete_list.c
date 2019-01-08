/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:56:05 by agesp             #+#    #+#             */
/*   Updated: 2019/01/08 14:13:51 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		complete_dot(const char *format, int *pos, t_plist *list)
{
	int		i;
	char	*save;
	int		digit;

	i = *pos;
	i++;
	while (ft_isdigit(format[i]) || format[i] == '*')
		i++;
	if (!(save = ft_strnew(i - *pos)))
		return (0);
	ft_strncpy(save, format + *pos + 1, i - *pos);
	digit = ft_atoi(save);
	free(save);
	if (digit == 0)
		list->precision = -1;
	else
		list->precision = digit;
	*pos = i;
	if (digit != 0 && list->precision == -1)
		return (1);
	return (0);
}

void	complete_width(const char *format, int *pos, t_plist *list)
{
	int		i;
	char	*save;
	int		digit;

	i = *pos;
	while (ft_isdigit(format[i]) || format[i] == '*')
		i++;
	if (!(save = ft_strnew(i - *pos)))
		return ;
	ft_strncpy(save, format + *pos, i - *pos);
	digit = ft_atoi(save);
	free(save);
	list->min_width = digit;
	*pos = i;
}

void	complete_convert(const char *format, int *pos, t_plist *list)
{
	int i;

	i = *pos;
	list->conversion = is_convert(format, i);
	if (list->conversion == 1 || list->conversion == 3
			|| list->conversion == 5)
		i++;
	else
		i += 2;
	*pos = i;
}

void	complete_start_sign(const char *format, int *pos)
{
	int	i;

	i = *pos;
	while (!is_sign(format, i) && !ft_isdigit(format[i])
			&& format[i] != '.' && !correct_flags(format, i)
			&& format[i] == '*')
		i++;
	*pos = i;
}

void	complete_sign(const char *format, int *pos, t_plist *list)
{
	int		i;
	int		j;

	i = *pos;
	j = 0;
	while ((is_sign(format, i) || format[i] == '*') && j < 4)
	{
		complete_start_sign(format, &i);
		if ((format[i] != '0' && format[i] != '*')
				|| (format[i] == '0' && format[i + 1] != '.'))
			list->sign[j] = format[i];
		if (format[i] == format[i + 1] && format[i] != '0')
			while (format[i] == format[i + 1])
				i++;
		if (format[i] == '0' && format[i + 1] == '.')
			break ;
		else
		{
			i++;
			j++;
		}
	}
	*pos = i;
}

void	complete_stars(va_list *ap, const char *format, int pos, t_plist *list)
{
	int	i;
	int	width;
	int	precision;
	int	flag;
	int save;

	i = 0;
	flag = 0;
		width = -1;
	precision = -1;
	save = 0;
	while (i < pos && format[i] != '%')
		i++;
	while (i < pos && format[i] != '.')
	{
		width = format[i] == '*' && width == -1 ? va_arg(*ap, int) : -1;
		if (format[i] == '*')
			flag = 1;
		if (width < 0 && width != -1)
		{
			width *= -1;
			list->sign[3] = '-';
		}
		i++;
	}
	if (format[i] == '.')
	{
		while (i < pos)
		{
			if (format[i] == '*')
				flag = 1;
			save = format[i] == '*' && precision == -1 ? va_arg(*ap, int) : 0;
			save = save < 0 && list->flag != 's' ? list->min_width : save;
			precision = format[i] == '*' && precision == -1 ? save : -1;
			i++;
		}
	}
	if (flag)
	{
		list->min_width = width != -1 ? width : list->min_width;
		list->precision = precision != -1 ? precision : list->precision;
		list->min_width = width == 0 ? -1 : list->min_width;
		list->precision = precision == 0 ? -1 : list->precision;
		list->precision = list->precision < -1 && list->flag == 's' ? 0 : list->precision;
	}
}

void	complete_list(const char *format, int *pos, t_plist *list, va_list *ap)
{
	int	i;
	int	save;

	i = *pos;
	save = 1;
	if (is_sign(format, i) || format[i] == '*')
		complete_sign(format, &i, list);
	*pos = i;
	if (ft_isdigit(format[i]) || format[i] == '*')
		complete_width(format, &i, list);
	*pos = i;
	if (format[i] == '.')
		save = complete_dot(format, &i, list);
	if (is_convert(format, i))
		complete_convert(format, &i, list);
	sort_flags(list, format[i]);
	if (save && list->flag != 's')
		list->precision = 0;
	remove_flag(list);
	complete_stars(ap, format, i, list);
	i++;
	*pos = i;
}
