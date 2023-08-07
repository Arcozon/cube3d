/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:23:41 by geudes            #+#    #+#             */
/*   Updated: 2023/08/07 13:25:12 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
