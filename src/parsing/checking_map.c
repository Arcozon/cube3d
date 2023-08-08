/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:36:16 by geudes            #+#    #+#             */
/*   Updated: 2023/08/08 18:19:31 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	is_player(char c)
{
	int	i;

	i = -1;
	while (USED_PLAYER[++i])
		if (USED_PLAYER[i] == c)
			return (1);
	return (0);
}

int	check_player(char **map)
{
	int	nbp;
	int	i;
	int	j;

	nbp = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (is_player(map[i][j]))
				nbp++;
	}
	if (nbp != 1)
		write (2, "Error: need one player\n", 23);
	return (nbp == 1);
}

void	*free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}

static int	not_next_to_empty(char c)
{
	return (c == NOT_NEXT_EMPTY || !c);
}

int	check_border(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == EMPTY || is_player(map[i][j]))
			{
				if (!i || not_next_to_empty(map[i - 1][j]))
					return (0);
				if (!map[i + 1] || not_next_to_empty(map[i + 1][j]))
					return (0);
				if (!j || not_next_to_empty(map[i][j -1]))
					return (0);
				if (not_next_to_empty(map[i][j + 1]))
					return (0);
			}
		}
	}
	return (1);
}
