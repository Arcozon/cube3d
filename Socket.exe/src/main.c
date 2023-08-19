/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:36:13 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 02:48:26 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int main(int ac, char **av, char **envp)
{
    t_my_socket my_socket;
    ((void)ac, (void)av, (void)envp);
    if (my_socket_create(&my_socket, 2))
        return (1);
    my_socket_write(my_socket, 1.012514f);
    return (0);
}