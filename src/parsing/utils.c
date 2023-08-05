/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:43 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 12:29:22 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	wildcard(char *patern, char *str)
{
	if (!patern[0] && !str[0])
		return (1);
	if (patern[0] == '*')
		while (patern[1] == '*')
			patern++;
	if (patern[0] == '*' && patern[1] && !str[0])
		return (0);
	if (patern[0] == str[0])
		return (wildcard(patern + 1, str + 1));
	if (patern[0] == '*')
		return (wildcard(patern + 1, str) || wildcard(patern, str + 1));
	return (0);
}

int	wildcard_nb(char *patern, char *str)
{
	if (!patern[0] && !str[0])
		return (1);
	if (patern[0] == '?' && patern[1] && !str[0])
		return (0);
	if (patern[0] == str[0])
		return (wildcard_nb(patern + 1, str + 1));
	if (patern[0] == '?')
		return (wildcard_nb(patern + 1, str) || (str[0] >= '0' && str[0] <= '9'
			&& wildcard_nb(patern + 1, str + 1)));
	return (0);
}

int	atouc(char	*str, int *rgb)
{
	int	i;

	i = 0;
	*rgb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		*rgb = *rgb * 10 + str[i] - '0';
		if (*rgb >= 256)
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	if (str[i] == ',')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}