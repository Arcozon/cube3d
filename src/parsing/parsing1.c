/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:11:11 by geudes            #+#    #+#             */
/*   Updated: 2023/08/04 12:52:18 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_not_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line != ' ' && line != '/t')
			return (1);
	return (0);
}

t_data	init_data(void)
{
	t_data	data;

	data.f = -1;
	data.c = -1;
	data.no = 0;
	data.ea = 0;
	data.we = 0;
	data.so = 0;
	return (data);
}

t_data	parsing_data(int fd)
{
	char	*line;
	t_data	data;

	data = init_data();
	while (!is_data_full(data))
	{
		line = gnl(fd);
		if (line && is_not_empty(line))
		{
			parsing_data1(line, &data);
		}
		free(line);
	}
}
