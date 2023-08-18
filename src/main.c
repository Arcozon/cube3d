/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:16:13 by geudes            #+#    #+#             */
/*   Updated: 2023/08/18 18:17:09 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	expand_image(t_image *image)
{
	image->mlx_image =
}

void	expand_images(t_data *data)
{

}

t_data	setup_argv(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2 || !wildcard("*.cub", av[1]))
		(printf("USAGE:\n   ./cube3d maps/example.cub\n"), exit(1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		(printf("Cant open %s\n", av[1]), exit(2));
	data = parsing_data(fd);
	close(fd);

	return (data);
}

int	main(int ac, char **av)
{
	static int	i = -1;
	t_data		data;

	data = setup_argv(ac, av);
	while (data.map[++i])
		printf("%s\n", data.map[i]);
	free_map(data.map);
	free_data(data);
}
