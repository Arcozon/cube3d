/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:35:45 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 20:01:37 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int     my_socket_write_float(t_my_socket my_socket, float to_write)
{
    uint    to_write_uint;
    char    my_char;
    int     i;

    to_write_uint = *(uint *)&to_write;
    i = 32;
    while (--i >= 0)
    {
        my_char = '0' + (to_write_uint >> i & 1);
        write(my_socket.fd, &my_char, 1);
    }
    write(my_socket.fd, "\n", 1);
    return (1);
}

// int     my_socket_write_float(t_my_socket my_socket, float to_write)
// {
//     uint    to_write_uint;
//     char    my_str[5];

//     to_write_uint = *(uint *)&to_write;
//     for(int i = 31; i>=0; i--)
//         printf("%c", ((to_write_uint >> i) & 1) + '0');
//     printf("\n");
//     my_str[0] = (to_write_uint & 0xff000000) >> 24;
//     my_str[1] = (to_write_uint & 0xff0000) >> 16;
//     my_str[2] = (to_write_uint & 0xff00) >> 8;
//     my_str[3] = to_write_uint & 0xff;
//     my_str[4] = '\n';
//     for(int i = 0; i<5; i++)
//         for(int j = 7; j>=0; j--)
//             printf("%c", ((my_str[i] >> j) & 1) + '0');
//     printf("\n");
//     write(my_socket.fd, my_str, 5);
//     return (1);
// }

int     my_socket_write_int(t_my_socket my_socket, int to_write)
{
    char    my_char;
    int     i;

    i = 32;
    while (--i >= 0)
    {
        my_char = '0' + (to_write >> i & 1);
        write(my_socket.fd, &my_char, 1);
    }
    write(my_socket.fd, "\n", 1);
    return (1);
}

int     my_socket_write_char(t_my_socket my_socket, char to_write)
{
    char    my_char;
    int     i;

    i = 8;
    while (--i >= 0)
    {
        my_char = '0' + (to_write >> i & 1);
        write(my_socket.fd, &my_char, 1);
    }
    write(my_socket.fd, "\n", 1);
    return (1);
}