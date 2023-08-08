/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixing_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 01:54:59 by geudes            #+#    #+#             */
/*   Updated: 2023/08/08 02:05:02 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int get_len_map(t_l_map *l_map)
{
    int i;

    i = 0;
    while (l_map)
        l_map = (++i, l_map->next);
    return (i);
}

int get_width_map(t_l_map *l_map)
{
    int max;

    max = 0;
    while(l_map)
    {
        if (ft_strlen(l_map->line) > max)
            max = ft_strlen(l_map->line);
        l_map = l_map->next;
    }
    return (max);.
}

char    **fixing_map(t_l_map l_map)
{
    int size[2];
    int i;
    int j;
    char    **res;

    size[1] = get_len_map(l_map) + 1;
    size[2] = get_width_map(l_map) + 1;
    res = malloc(sizeof(char *) * size[0]);
    if (!res)
        return (0);
    i = -1;
    while (res[++i])
    {
        res[i] = malloc(sizeof(char) * size[1]);
    }
    
}