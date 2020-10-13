/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:38:02 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/08 18:01:10 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_list
{
	int	width;
	int	spaces;
	int	zeros;
	int precision;
}				t_list;

int				ft_printf(const char *str, ...);
int				parse(const char *str, va_list args);
void			ft_print_args(const char *str, int *i,
				int *result, va_list args);
void			ft_get_format(t_list *to_print, const char *str,
				int *i, va_list args);
void			ft_precision(t_list *to_print, const char *str,
				int *i, va_list args);
int				ft_print_result(t_list to_print, const char *str,
				int *i, va_list args);
void			print_char(t_list to_print, int *j, int *k, va_list args);
void			print_char_part(t_list to_print, int *j, int *k);
void			print_string(t_list to_print, int *j, int *k, va_list args);
void			print_created_strings(t_list to_print, int *j,
				char *str, int *k);
void			print_created_strings_i(t_list to_print, int *j,
				char *str, int *k);
void			print_integer(t_list to_print, int *j, int *k, va_list args);
void			print_integer_i(t_list to_print, int *j, int *k, va_list args);
void			print_unsigned(t_list to_print, int *j, int *k, va_list args);
void			print_void(t_list to_print, int *j, va_list args);
void			print_x(t_list to_print, int *j, int *k, va_list args);
void			print_x_maj(t_list to_print, int *j, int *k, va_list args);
int				taille_malloc(long nb, char *base_hexa, unsigned int *k);
void			print_spaces(t_list to_print, int i, int *k);
char			*ft_strlcpy_printf(char *str, int k);
int				ft_atoi(char *str);
int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd, int *k);
char			*ft_substr(char const *s, int start, size_t len);
char			*ft_strdup(const char *s1);
void			ft_putstr_fd(char *s, int fd, int *k);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned int nb, char *base_hexa);
char			*ft_itoa_base_p(long nb, char *base);
char			*ft_itoa_unsigned(unsigned int n);
void			print_pointer(t_list to_print, int *j, int *k, va_list args);
char			*ft_strjoin(char *s1, char *s2);
void			print_preci_int_null(t_list to_print, int *j, int *k);
char			*ft_cpynull(int l);
void			ft_width(t_list *to_print, const char *str,
				int *i, va_list args);
void			print_p(t_list to_print, char *str, int *j, int *k);

#endif
