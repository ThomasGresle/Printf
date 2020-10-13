/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:30:39 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:18 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse(const char *str, va_list args)
{
	int	i;
	int j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (str && str[i])
	{
		while (str && str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1, &j);
			result++;
		}
		if (str && str[i] && str[i] == '%')
		{
			i++;
			ft_print_args(str, &i, &result, args);
		}
	}
	return (result);
}

void	ft_print_args(const char *str, int *i, int *result, va_list args)
{
	t_list	to_print;

	to_print.precision = -1;
	to_print.spaces = 0;
	to_print.width = 0;
	to_print.zeros = 0;
	while (str && str[*i] && str[(*i) + 1] && (str[*i] == '-'
	|| str[*i] == '.' || str[(*i)] == '*' || (str[*i] < 58 && str[*i] > 47)))
		ft_get_format(&to_print, str, i, args);
	*result += ft_print_result(to_print, str, i, args);
}

void	ft_get_format(t_list *to_print, const char *str, int *i, va_list args)
{
	if (str[(*i)] == '0')
	{
		to_print->zeros = 1;
		(*i)++;
	}
	if (str[(*i)] == '-')
	{
		to_print->spaces = 1;
		(*i)++;
	}
	if ((str[(*i)] < 58 && str[(*i)] > 47) || str[(*i)] == '*')
	{
		ft_width(to_print, str, i, args);
		if (to_print->width < 0)
		{
			to_print->spaces = 1;
			to_print->width *= -1;
		}
	}
	ft_precision(to_print, str, i, args);
}

void	ft_precision(t_list *to_print, const char *str, int *i, va_list args)
{
	char	*number;
	int		j;

	j = 0;
	if (str && str[(*i)] && str[(*i)] == '.')
	{
		(*i)++;
		if (str[(*i)] == '*')
		{
			(*i)++;
			to_print->precision = (int)va_arg(args, int);
			if (to_print->precision == -1)
				to_print->precision = -2;
		}
		else
		{
			while (str && str[(*i) + j]
			&& str[(*i) + j] < 58 && str[(*i) + j] > 47)
				j++;
			number = ft_substr(str, *i, j);
			to_print->precision = ft_atoi(number);
			*i += j;
		}
		to_print->zeros = to_print->precision > -1 ? 0 : to_print->zeros;
	}
}

int		ft_print_result(t_list to_print, const char *str, int *i, va_list args)
{
	int	j;
	int	k;

	j = to_print.width;
	k = 0;
	if (str[*i] == 'c')
		print_char(to_print, &j, &k, args);
	if (str[*i] == '%')
		print_char_part(to_print, &j, &k);
	if (str[*i] == 's')
		print_string(to_print, &j, &k, args);
	if (str[*i] == 'd')
		print_integer_i(to_print, &j, &k, args);
	if (str[*i] == 'i')
		print_integer_i(to_print, &j, &k, args);
	if (str[*i] == 'u')
		print_unsigned(to_print, &j, &k, args);
	if (str[*i] == 'p')
		print_pointer(to_print, &j, &k, args);
	if (str[*i] == 'x')
		print_x(to_print, &j, &k, args);
	if (str[*i] == 'X')
		print_x_maj(to_print, &j, &k, args);
	(*i)++;
	return (k);
}
