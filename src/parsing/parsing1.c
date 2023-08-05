/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:11:11 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 12:36:14 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	is_not_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
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
		|| data.we == 0 || data.so == 0));
}

int	parsing_color(char *line)
{
	int	rgb[3];
	int	atouc_ret;

	line += 2;
	atouc_ret = atouc(line, rgb);
	if (atouc_ret == -1)
		return (-1);
	line += atouc_ret;
	atouc_ret = atouc(line, rgb + 1);
	if (atouc_ret == -1)
		return (-1);
	line += atouc_ret;
	atouc_ret = atouc(line, rgb + 2);
	if (atouc_ret == -1)
		return (-1);
	return (0xffffff & (rgb[0] << 16 | rgb[1] << 8 | rgb[2]));
}

t_data	parsing_data(int fd)
{
	char	*line;
	t_data	data;

	data = init_data();
	line = gnl(fd);
	while (!is_data_full(data) && line)
	{
		if (line && is_not_empty(line))
		{
			if (wildcard_nb(PATERN_C, line))
				data.c = parsing_color(line);
			else if (wildcard_nb(PATERN_F, line))
				data.f = parsing_color(line);
			else if (wildcard(PATERN_NO, line))
				data.no = ft_strdup(line + 3);
			else if (wildcard(PATERN_SO, line))
				data.so = ft_strdup(line + 3);
			else if (wildcard(PATERN_EA, line))
				data.ea = ft_strdup(line + 3);
			else if (wildcard(PATERN_WE, line))
				data.we = ft_strdup(line + 3);
		}
		free(line);
		line = 0;
		if (!is_data_full(data))
			line = gnl(fd);
	}
	return (data);
}
