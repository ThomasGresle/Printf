/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:16:04 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:29 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_integer(t_list to_print, int *j, int *k, va_list args)
{
	int		i;
	int		l;
	char	*str;

	i = (int)va_arg(args, int);
	l = 0;
	if (to_print.precision > 0)
		to_print.zeros = 0;
	if (!(i == 0 && to_print.precision == 0))
	{
		str = ft_itoa(i);
		if (to_print.precision < ft_strlen(str))
			to_print.precision = ft_strlen(str);
		else
		{
			l = to_print.precision - ft_strlen(str);
			while (l-- > 0)
				str = ft_strjoin("0", str);
		}
		print_created_strings(to_print, j, str, k);
		free(str);
	}
}

void	print_unsigned(t_list to_print, int *j, int *k, va_list args)
{
	unsigned	int	i;
	int				l;
	char			*str;

	i = (unsigned int)va_arg(args, unsigned int);
	l = 0;
	if (to_print.precision > 0)
		to_print.zeros = 0;
	if (i == 0 && to_print.precision == 0)
		print_preci_int_null(to_print, j, k);
	else
	{
		str = ft_itoa_unsigned(i);
		if (to_print.precision < ft_strlen(str))
			to_print.precision = ft_strlen(str);
		else
		{
			l = to_print.precision - ft_strlen(str);
			while (l-- > 0)
				str = ft_strjoin("0", str);
		}
		print_created_strings(to_print, j, str, k);
		free(str);
	}
}

void	print_x(t_list to_print, int *j, int *k, va_list args)
{
	unsigned	int	i;
	int				l;
	char			*str;

	i = (unsigned int)va_arg(args, unsigned int);
	l = 0;
	if (i == 0 && to_print.precision == 0)
		print_preci_int_null(to_print, j, k);
	else
	{
		str = ft_itoa_base(i, "0123456789abcdef");
		if (to_print.precision < ft_strlen(str))
			to_print.precision = ft_strlen(str);
		else
		{
			l = to_print.precision - ft_strlen(str);
			while (l-- > 0)
				str = ft_strjoin("0", str);
		}
		print_created_strings(to_print, j, str, k);
		free(str);
	}
}

void	print_x_maj(t_list to_print, int *j, int *k, va_list args)
{
	unsigned	int	i;
	int				l;
	char			*str;

	i = (unsigned int)va_arg(args, unsigned int);
	l = 0;
	if (i == 0 && to_print.precision == 0)
		print_preci_int_null(to_print, j, k);
	else
	{
		str = ft_itoa_base(i, "0123456789ABCDEF");
		if (to_print.precision < ft_strlen(str))
			to_print.precision = ft_strlen(str);
		else
		{
			l = to_print.precision - ft_strlen(str);
			while (l-- > 0)
				str = ft_strjoin("0", str);
		}
		print_created_strings(to_print, j, str, k);
		free(str);
	}
}
