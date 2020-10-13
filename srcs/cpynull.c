/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpynull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:12:23 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:24:56 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_cpynull(int l)
{
	char	*str;
	char	*src;
	int		i;

	str = NULL;
	src = "(null)";
	i = 0;
	if (l < 0)
		l = 7;
	if (!(str = malloc(sizeof(char) * (l + 1))))
		return (0);
	while (i < l)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_width(t_list *to_print, const char *str, int *i, va_list args)
{
	char	*number;
	int		j;

	j = 0;
	if (str[(*i)] == '*')
	{
		to_print->width = (int)va_arg(args, int);
		if (to_print->width < 0)
		{
			to_print->zeros = 0;
			to_print->spaces = 1;
		}
		(*i)++;
	}
	else
	{
		while (str && str[(*i) + j]
		&& str[(*i) + j] < 58 && str[(*i) + j] > 47)
			j++;
		number = ft_substr(str, *i, j);
		to_print->width = ft_atoi(number);
		*i += j;
	}
}

void	print_p(t_list to_print, char *str, int *j, int *k)
{
	if (to_print.precision == 0 && ft_strlen(str) == 3 && str[2] == '0')
	{
		free(str);
		if (!(str = malloc(sizeof(char) * 3)))
			return ;
		str[0] = '0';
		str[1] = 'x';
		str[2] = '\0';
	}
	*j -= ft_strlen(str);
	if (to_print.spaces == 0)
	{
		print_spaces(to_print, *j, k);
		ft_putstr_fd(str, 1, k);
	}
	else
	{
		ft_putstr_fd(str, 1, k);
		print_spaces(to_print, *j, k);
	}
}
