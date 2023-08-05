/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:11:11 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 01:11:11 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	is_not_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line != ' ' && line != '/t')
			return (1);
	return (0);
}

static t_data	init_data(void)
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

int	is_data_full(t_data data)
{
	return (!(data.f == -1 || data.c == -1 || data.no == 0 || data.ea == 0
		| data.we == 0 || data.so == 0|))
}

int	parsing_color(char *line)
{
	int	color;
	int	i;

	color = 0;
	
}

void	parsing_data1(char *line, t_data *data)
{
	if (wildcard(PATERN_C, line))
		data->c = parsing_color(line);
	else if (wildcard(PATERN_F, line))
		data->f = parsing_color(line);
	else if (wildcard(PATERN_NO, line))
	else if (wildcard(PATERN_SO, line))
	else if (wildcard(PATERN_EA, line))
	else if (wildcard(PATERN_WE, line))
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
