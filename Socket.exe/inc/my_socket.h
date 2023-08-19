/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:41:55 by geudes            #+#    #+#             */
/*   Updated: 2023/08/19 03:04:14 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
# define SOCKET_H

// Create  a "Socket" to trade float with other processes

# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h> 
# include <fcntl.h>
# include <unistd.h>

# define MAX_PLAYER 8
# define P_NAME_LEN 2

typedef struct s_my_socket
{
    int     nb_player;
    char   *fd_name;
    int    fd;
    char   *sema_name;
    sem_t  *sema;
}       t_my_socket;

int     my_socket_create(t_my_socket *my_socket, int nb_player);
// int     my_socket_join(t_my_socket *my_socket, );

int     my_socket_reset(t_my_socket *my_socket);
int     my_socket_write(t_my_socket my_socket, float to_write);
// int     my_socket_read();

void    my_socket_leave(t_my_socket my_socket);
void    my_socket_close(t_my_socket my_socket);

char    *s_get_fd_name(void);
char    *s_get_sema_name(void);


int s_strlen(char *str);

#endif