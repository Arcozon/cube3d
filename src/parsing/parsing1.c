/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:11:11 by geudes            #+#    #+#             */
/*   Updated: 2023/08/07 14:41:37 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_not_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
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

int	is_data_full(t_data data)
{
	return (!(data.f == -1 || data.c == -1 || data.no == 0 || data.ea == 0
			|| data.we == 0 || data.so == 0));
}

int	parsing_color(char *linetf, t_data data, int fd, int old)
{
	int		rgb[3];
	int		atouc_ret;
	char	*line;

	if (old != -1)
		free_data_line(data, linetf, fd, "Color already set");
	line = linetf + 2;
	atouc_ret = atouc(line, rgb, 0);
	if (atouc_ret == -1)
		free_data_line(data, linetf, fd, "Wrong first color format");
	line += atouc_ret;
	atouc_ret = atouc(line, rgb + 1, 0);
	if (atouc_ret == -1)
		free_data_line(data, linetf, fd, "Wrong second color format");
	line += atouc_ret;
	atouc_ret = atouc(line, rgb + 2, 1);
	if (atouc_ret == -1 || line[atouc_ret])
		free_data_line(data, linetf, fd, "Wrong third color format");
	return (((rgb[0] & 0xff) << 16 | (rgb[1] & 0xff) << 8 | (rgb[2] & 0xff)));
}
