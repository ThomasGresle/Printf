/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:11:09 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:14 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char_part(t_list to_print, int *j, int *k)
{
	char	c;

	c = '%';
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
