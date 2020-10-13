/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:13:47 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:06 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	decades(unsigned int n)
{
	int i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	int		i;
	int		j;
	char	*str;

	i = decades(n);
	j = 0;
	j = n < 0 ? 1 : 0;
	if (!(str = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	str[i-- + j] = '\0';
	if (n < 0)
		n *= -1;
	while ((i + j) >= 0)
	{
		str[i-- + j] = n % 10 + '0';
		n /= 10;
	}
	if (j == 1)
		str[0] = '-';
	return (str);
}
