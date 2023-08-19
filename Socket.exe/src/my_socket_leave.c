/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_leave.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:13:30 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 02:16:15 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

void    my_socket_leave(t_my_socket my_socket)
{
    close(my_socket.fd);
    free(my_socket.fd_name);
    sem_close(my_socket.sema);
    free(my_socket.sema_name);
}