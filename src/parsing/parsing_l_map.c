/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:43:25 by geudes            #+#    #+#             */
/*   Updated: 2023/08/08 16:12:35 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	composed_used_char(char *str)
{
	int	imin;
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		imin = 0;
		j = -1;
		while (USED_CHAR[++j] && !imin)
			imin = (str[i] == USED_CHAR[j]);
		if (!imin)
			return (0);
	}
	return (1);
}

// 1 on success 0 on error
int	l_map_addback(char *line, t_l_map **l_map)
{
	t_l_map	*new;

	new = malloc(sizeof(t_l_map));
	if (new)
	{
		new->next = 0;
		new->line = line;
		while (*l_map)
			l_map = &((*l_map)->next);
		*l_map = new;
	}
	else
		return (free(line), 0);
	return (1);
}

void	free_l_map(t_l_map *l_map)
{
	t_l_map	*next;

	while (l_map)
	{
		next = l_map->next;
		free(l_map->line);
		free(l_map);
		l_map = next;
	}
}

t_l_map	*get_l_map(int fd)
{
	char	*line;
	t_l_map	*l_map;

	l_map = 0;
	line = gnl(fd);
	while (!is_not_empty(line))
		line = (free(line), gnl(fd));
	if (!composed_used_char(line))
		return (free(line), (t_l_map *)0);
	while (line)
	{
		if (!l_map_addback(line, &l_map))
			return (free_l_map(l_map), (t_l_map *)0);
		line = gnl(fd);
	}
	return (l_map);
}
