/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:13:15 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:33 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = (ft_strlen(s1) + ft_strlen(s2));
	k = 0;
	if (!(str = malloc(sizeof(char) * (j + 1))))
		return (0);
	if (!(str))
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s2);
	return (str);
}
