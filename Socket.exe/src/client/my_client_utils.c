/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:52:58 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 05:33:35 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

char    *c_get_rfd_name(char *user)
{
    char    *res ;
    int     i;

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

char    *c_get_sema_name(char *user)
{
    char    *res ;
    int     i;

    res = malloc(4 + s_strlen(user) + 1);
    if (!res)
        return (NULL);
    i = -1;
    res[0] = 'S';
    res[1] = 'E';
    res[2] = 'M';
    res[3] = 'A';
    while (user[++i])
        res[i + 4] = user[i];
    res[s_strlen(user) + 4] = 0;
    return (res);
}

char    *c_get_wfd_name(char *user, int id)
{
    char    *res ;
    int     i;

    res = malloc(2 + s_strlen(user) + 2);
    if (!res)
        return (NULL);
    i = -1;
    res[0] = 'F';
    res[1] = 'D';
    while (user[++i])
        res[i + 2] = user[i];
    res[s_strlen(user) + 2] = '0' + id;
    res[s_strlen(user) + 3] = 0;
    return (res);
}