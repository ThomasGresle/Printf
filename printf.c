/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:23:26 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:26:01 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		result;
	va_list args;

	va_start(args, str);
	result = parse(str, args);
	va_end(args);
	return (result);
}
