/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:16:13 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 13:30:58 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
    (void)ac, (void)av;
    int fd = open("map.cub", O_RDONLY);
    if (fd == -1)
        return (0);
    char *line;
    do
    {
        line = gnl(fd);
        printf("%s\n", line);
        free(line);
    }   while (line);
    return 1;
    t_data data = parsing_data(fd);

    printf("C %d %d %d\n", data.c & 0xff0000 >> 16, data.c & 0xff00 >> 8, data.c & 0xff);
    printf("F %d %d %d\n", data.f & 0xff0000 >> 16, data.f & 0xff00 >> 8, data.f & 0xff);

    printf("NO %s\n", data.no);
    printf("EA %s\n", data.ea);
    printf("WE %s\n", data.we);
    printf("SO %s\n", data.so);
}