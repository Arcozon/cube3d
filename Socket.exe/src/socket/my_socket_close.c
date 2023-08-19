/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:17:32 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 02:43:57 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

void    my_socket_close(t_my_socket my_socket)
{
    unlink(my_socket.fd_name);
    close(my_socket.fd);
    free(my_socket.fd_name);
    sem_close(my_socket.sema);
    sem_unlink(my_socket.sema_name);
    free(my_socket.sema_name);
}