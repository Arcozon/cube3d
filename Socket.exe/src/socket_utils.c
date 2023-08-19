/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:54:16 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 02:11:27 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

char    *s_get_fd_name(void)
{
    char    *res ;
    char    *user;
    int     i;

    user = getenv("USER");
    res = malloc(2 + s_strlen(user) + 1);
    if (!res)
        return (NULL);
    i = -1;
    res[0] = 'F';
    res[1] = 'D';
    while (user[++i])
        res[i + 2] = user[i];
    res[s_strlen(user) + 2] = 0;
    return (res);
}

char    *s_get_sema_name(void)
{
    char    *res ;
    char    *user;
    int     i;

    user = getenv("USER");
    res = malloc(4 + s_strlen(user) + 1);
    if (!res)
        return (NULL);
    i = -1;
    res[0] = 'S';
    res[1] = 'E';
    res[1] = 'M';
    res[1] = 'A';
    while (user[++i])
        res[i + 4] = user[i];
    res[s_strlen(user) + 4] = 0;
    return (res);
}

int s_strlen(char *str)
{
    int i;

    i = -1;
    while(str[++i])
        ;
    return (i);
}