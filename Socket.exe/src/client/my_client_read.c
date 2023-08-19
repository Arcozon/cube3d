/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:21:02 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 05:30:17 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int     my_client_read_float(t_my_client my_client, float *to_read)
{
    uint    to_read_uint;
    char    my_char;
    int     i;

    i = 32;
    to_read_uint = 0;
    while (--i >= 0)
    {
        read(my_client.read_fd, &my_char, 1);
        to_read_uint <<= 1;
        to_read_uint |= (my_char == '1');
    }
    read(my_client.read_fd, &my_char, 1);
    *(uint *)to_read = to_read_uint;
    return (1);
}

int     my_client_read_int(t_my_client my_client, int *to_read)
{
    char    my_char;
    int     i;

    i = 32;
    *to_read = 0;
    while (--i >= 0)
    {
        read(my_client.read_fd, &my_char, 1);
        *to_read <<= 1;
        *to_read |= (my_char == '1');
    }
    read(my_client.read_fd, &my_char, 1);
    return (1);
}

int     my_client_read_char(t_my_client my_client, char *to_read)
{
    char    my_char;
    int     i;

    i = 8;
    *to_read = 0;
    while (--i >= 0)
    {
        read(my_client.read_fd, &my_char, 1);
        *to_read <<= 1;
        *to_read |= (my_char == '1');
    }
    read(my_client.read_fd, &my_char, 1);
    return (1);
}