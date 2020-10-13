/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:36:21 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:21 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_substr_i(char const *s, unsigned int start)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s)))))
		return (0);
	if (!(str))
		return (NULL);
	while (s && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

void	print_preci_int_null(t_list to_print, int *j, int *k)
{
	int	l;

	l = 0;
	if (to_print.zeros == 0 || to_print.spaces != 0)
	{
		while (l < to_print.width)
		{
			ft_putchar_fd(' ', 1, k);
			(*j)++;
			l++;
		}
	}
	else
	{
		while (l < to_print.width)
		{
			ft_putchar_fd('0', 1, k);
			(*j)++;
			l++;
		}
	}
}

void	print_i_neg(t_list to_print, char *dst, int j, int *k)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_substr_i(dst, 1);
	free(dst);
	while (i < j)
	{
		str = ft_strjoin("0", str);
		i++;
	}
	str = ft_strjoin("-", str);
	j = to_print.width - ft_strlen(str);
	if (to_print.spaces == 0)
	{
		print_spaces(to_print, j, k);
		ft_putstr_fd(str, 1, k);
	}
	else
	{
		ft_putstr_fd(str, 1, k);
		print_spaces(to_print, j, k);
	}
	free(str);
}

void	print_created_strings_i(t_list to_print, int *j, char *str, int *k)
{
	int	i;

	i = to_print.precision > to_print.width ?
	to_print.precision : (to_print.width - ft_strlen(str));
	if (to_print.precision > 0)
		i = to_print.precision - (ft_strlen(str) - 1);
	*j -= ft_strlen(str);
	if (str[0] != '-' || (to_print.precision <= 0 && to_print.zeros == 0))
	{
		if (ft_strlen(str) == 1 && str[0] == '0' && to_print.precision == 0)
			print_preci_int_null(to_print, j, k);
		else if (to_print.spaces == 0)
		{
			print_spaces(to_print, *j, k);
			ft_putstr_fd(str, 1, k);
		}
		else
		{
			ft_putstr_fd(str, 1, k);
			print_spaces(to_print, *j, k);
		}
		free(str);
	}
	else
		print_i_neg(to_print, str, i, k);
}

void	print_integer_i(t_list to_print, int *j, int *k, va_list args)
{
	int		i;
	int		l;
	char	*str;

	i = (int)va_arg(args, int);
	l = 0;
	if (to_print.precision > 0)
		to_print.zeros = 0;
	if (!(i == 0 && to_print.precision == 0 && to_print.width == 0))
	{
		str = ft_itoa(i);
		if (str[0] != '-')
		{
			l = to_print.precision - ft_strlen(str);
			while (l-- > 0)
				str = ft_strjoin("0", str);
		}
		print_created_strings_i(to_print, j, str, k);
	}
}
