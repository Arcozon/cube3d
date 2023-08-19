/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:36:13 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 12:37:21 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int main(int ac, char **av, char **envp)
{
    t_my_socket my_socket;
    t_my_client my_client;
    float       my_float;

    ((void)ac, (void)av, (void)envp);
    if (my_socket_create(&my_socket, 2))
        return (1);
    if (my_client_join(&my_client, getenv("USER")))
        return (2);
    my_socket_write_float(my_socket, 1.012514f);
    my_socket_close(my_socket);
    my_client_read_float(my_client, &my_float);
    printf("%f\n", my_float);
    my_client_leave(my_client);
    return (0);
}