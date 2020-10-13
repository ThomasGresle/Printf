/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:12:43 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:24:58 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base_p(long nb, char *base_hexa)
{
	unsigned	int	k;
	int				c;
	char			*nb_final;

	k = 0;
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
