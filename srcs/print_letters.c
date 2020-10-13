/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:14:52 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:25 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(t_list to_print, int *j, int *k, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	*j -= 1;
	if (to_print.spaces == 0)
	{
		print_spaces(to_print, *j, k);
		ft_putchar_fd(c, 1, k);
	}
	else
	{
		ft_putchar_fd(c, 1, k);
		print_spaces(to_print, *j, k);
	}
}

void	print_string(t_list to_print, int *j, int *k, va_list args)
{
	char	*str;
	char	*dst;
	int		l;

	str = (char *)va_arg(args, char *);
	l = to_print.precision;
	l = l < -1 ? ft_strlen(str) : to_print.precision;
	dst = NULL;
	if (*j <= l && l >= ft_strlen(str) && ft_strlen(str) >= *j)
		*j = 0;
	dst = str == NULL ? ft_cpynull(to_print.precision)
		: ft_strlcpy_printf(str, l);
	*j -= ft_strlen(dst);
	if (to_print.spaces == 0)
	{
		print_spaces(to_print, *j, k);
		ft_putstr_fd(dst, 1, k);
	}
	else
	{
		ft_putstr_fd(dst, 1, k);
		print_spaces(to_print, *j, k);
	}
	*j += ft_strlen(dst) * 2;
	free(dst);
}

void	print_pointer(t_list to_print, int *j, int *k, va_list args)
{
	long	i;
	char	*str;
	int		check;

	i = (long)va_arg(args, long);
	check = 0;
	if (i < 0)
	{
		i += 4294967296;
		check = 1;
	}
	str = ft_itoa_base_p(i, "0123456789abcdef");
	if (check == 0)
		str = ft_strjoin("0x", str);
	else
		str = ft_strjoin("0xffffffff", str);
	print_p(to_print, str, j, k);
	*j += ft_strlen(str) * 2;
	free(str);
}

void	ft_putchar_fd(char c, int fd, int *k)
{
	if (fd >= 0)
		write(fd, &c, 1);
	(*k)++;
}

void	ft_putstr_fd(char *s, int fd, int *k)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		if (fd >= 0)
		{
			while (s[i])
			{
				ft_putchar_fd(s[i], fd, k);
				i++;
			}
		}
	}
}
