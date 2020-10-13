/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:14:13 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:40 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		taille_malloc(long nb, char *base_hexa, unsigned int *k)
{
	long b;

	b = 1;
	while (base_hexa[*k] != '\0')
		(*k)++;
	while (nb >= *k)
	{
		nb = nb / *k;
		b++;
	}
	return (b);
}

char	*ft_itoa_base(unsigned int nb, char *base_hexa)
{
	unsigned	int	k;
	int				c;
	char			*nb_final;

	k = 0;
	if (nb < 0)
		nb = nb * -1;
	c = taille_malloc(nb, base_hexa, &k);
	if (!(nb_final = (char*)malloc(sizeof(char) * (c + 1))))
		return (0);
	if (nb_final == NULL)
		return (0);
	nb_final[c] = '\0';
	while (c > 0)
	{
		c--;
		nb_final[c] = base_hexa[nb % k];
		nb = nb / k;
	}
	return (nb_final);
}

char	*ft_strlcpy_printf(char *str, int k)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	if (k == -1)
		k = ft_strlen(str);
	if (ft_strlen(str) <= k)
		j = ft_strlen(str);
	else
		j = k;
	if (!(dst = malloc(sizeof(char) * (j + 1))))
		return (0);
	while (i < k && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	print_created_strings(t_list to_print, int *j, char *str, int *k)
{
	char	*dst;
	int		l;

	l = to_print.precision;
	dst = NULL;
	if (*j <= l && l >= ft_strlen(str) && ft_strlen(str) >= *j)
		*j = 0;
	dst = ft_strlcpy_printf(str, l);
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
}

void	print_spaces(t_list to_print, int i, int *k)
{
	int	l;

	l = 0;
	if (to_print.zeros == 0 || to_print.spaces != 0)
	{
		while (l < i)
		{
			ft_putchar_fd(' ', 1, k);
			l++;
		}
	}
	else
	{
		while (l < i)
		{
			ft_putchar_fd('0', 1, k);
			l++;
		}
	}
}
