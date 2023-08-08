/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixing_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 01:54:59 by geudes            #+#    #+#             */
/*   Updated: 2023/08/08 18:11:55 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_len_map(t_l_map *l_map)
{
	int	i;

	i = 0;
	while (l_map)
		l_map = (++i, l_map->next);
	return (i);
}

int	get_width_map(t_l_map *l_map)
{
	int	max;

	max = 0;
	while (l_map)
	{
		if (ft_strlen(l_map->line) > max)
			max = ft_strlen(l_map->line);
		l_map = l_map->next;
	}
	return (max);
}

char	**malloc_map(t_l_map *l_map)
{
	int		size[2];
	int		i;
	char	**res;

	size[0] = get_len_map(l_map);
	size[1] = get_width_map(l_map) + 1;
	res = ft_calloc(sizeof(char *) * (size[0] + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < size[0])
	{
		res[i] = ft_calloc(sizeof(char) * size[1]);
		if (!res[i])
		{
			while (--i >= 0)
				free(res[i]);
			return (free(res), (char **)0);
		}
	}
	return (res);
}

char	**map_is_a_square(t_l_map *l_map)
{
	int		i;
	int		j;
	char	**res;

	res = malloc_map(l_map);
	if (!res)
		return (0);
	i = 0;
	while (l_map)
	{
		j = -1;
		while (l_map->line[++j])
			res[i][j] = l_map->line[j];
		l_map = l_map->next;
		i++;
	}
	return (res);
}

char	**map_bs(int fd)
{
	t_l_map	*lmap;
	char	**map;

	lmap = get_l_map(fd);
	if (!lmap)
		return (0);
	map = map_is_a_square(lmap);
	free_l_map(lmap);
	if (!map)
		return (0);
	if (!check_player(map))
		return (free_map(map));
	if (!check_border(map))
		return (write(2, "Error: Map must be closed\n", 26), free_map(map));
	return (map);
}
