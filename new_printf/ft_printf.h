#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_plist
{
	int	flag;
	int	conversion;
	int	precision;
	int	min_width;
	char	sign[4];
	int		size;
}			t_plist;


int		ft_printf(const char *format, ...);
int		correct_flags(const char *format, int i);
int		is_dioux(const char *format, int i);
int		is_sign(const char *format, int i);
int		is_csp(const char *format, int i);
int		is_convert(const char *format, int i);
void	complete_list(const char *format, int *pos, t_plist *list);
int		print_list(t_plist *list, va_list *ap);
void	w_print_char(wchar_t c);
void	w_print_str(wchar_t *s);
int		print_wp(t_plist *list, int len, char zero, int ou);
void	print_x(t_plist *list, va_list *ap);
void	print_s(t_plist *list, va_list *ap);
void	print_u(t_plist *list, va_list *ap);
void	print_o(t_plist *list, va_list *ap);
void	print_int(t_plist *list, va_list *ap);
void	print_percent(t_plist *list);
void	print_c(t_plist *list, va_list *ap);

#endif