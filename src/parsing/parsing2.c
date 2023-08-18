/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:24:31 by geudes            #+#    #+#             */
/*   Updated: 2023/08/18 17:59:38 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*handle_img(int fd, t_data *data, char *line, char *old)
{
	char	*res;

	if (old)
		free_data_line(*data, line, fd, "Arg already set");
	res = ft_strdup(line + 3);
	if (!res)
		free_data_line(*data, line, fd, "Malloc error");
	return (res);
}

void	parsing_data2(int fd, t_data *data, char *line)
{
	if (wildcard_nb(PATERN_C, line))
		data->c = parsing_color(line, *data, fd, data->c);
	else if (wildcard_nb(PATERN_F, line))
		data->f = parsing_color(line, *data, fd, data->f);
	else if (wildcard(PATERN_NO, line))
		data->no.name = handle_img(fd, data, line, data->no.name);
	else if (wildcard(PATERN_SO, line))
		data->so.name = handle_img(fd, data, line, data->so.name);
	else if (wildcard(PATERN_EA, line))
		data->ea.name = handle_img(fd, data, line, data->ea.name);
	else if (wildcard(PATERN_WE, line))
		data->we.name = handle_img(fd, data, line, data->we.name);
	else
		free_data_line(*data, line, fd, "Unrecognized line");
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
			parsing_data2(fd, &data, line);
		free(line);
		line = 0;
		if (!is_data_full(data))
			line = gnl(fd);
	}
	if (!is_data_full(data))
		free_data_line(data, 0, fd, "Missing data");
	data.map = map_bs(fd);
	if (!data.map)
		(free_data(data), close(fd), exit(1));
	return (data);
}

void	free_data(t_data data)
{
	free(data.no.name);
	free(data.so.name);
	free(data.ea.name);
	free(data.we.name);
}

void	free_data_line(t_data data, char *line, int fd, char *error)
{
	free_data(data);
	free(line);
	close(fd);
	write(2, "Error: Parsing: ", 17);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}
