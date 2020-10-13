/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:47:47 by tgresle           #+#    #+#             */
/*   Updated: 2020/10/09 14:25:37 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	check(const char *str, int *i, int *erreur)
{
	while (str && str[(*i)] && (str[*i] == ' ' || str[*i] == '\t'
		|| str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r'))
	{
		(*i)++;
	}
	if (str[*i] == '\0' || (str[*i] != '+'
		&& str[*i] != '-' && (str[*i] < 48 && str[*i] > 57)))
	{
		*erreur = 1;
		return (0);
	}
	else if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

int			ft_atoi(char *str)
{
	int	i;
	int	resultat;
	int	erreur;
	int	signe;

	i = 0;
	resultat = 0;
	erreur = 0;
	signe = check(str, &i, &erreur);
	if (erreur == 1)
		return (0);
	while (str && str[i] && str[i] >= 48 && str[i] <= 57)
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	free(str);
	return (resultat * signe);
}

int			ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_substr(char const *s, int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!(str))
		return (NULL);
	while (s && s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	if (!(str))
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
