/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:48:52 by geudes            #+#    #+#             */
/*   Updated: 2023/08/24 16:48:59 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

static void	init_rfd(t_my_socket *my_socket)
{
	int	i;

	i = -1;
	while (++i < MAX_PLAYER)
	{
		my_socket->p_fd[i] = -1;
		my_socket->pfd_name[i] = 0;
	}
}

static int	malloc_read_fd(t_my_socket *my_socket)
{
	int	i;

	init_rfd(my_socket);
	i = -1;
	while (++i < my_socket->nb_player)
	{
		my_socket->pfd_name[i] = s_get_rfd_name(i);
		if (!my_socket->pfd_name[i])
		{
			while (--i >= 0)
				free(my_socket->pfd_name[i]);
			return (-1);
		}
	}
	return (0);
}

int	my_socket_create(t_my_socket *my_socket, int nb_player)
{
	if (nb_player < 1 || nb_player > MAX_PLAYER)
		return (-1);
	my_socket->nb_player = nb_player;
	my_socket->fd_name = s_get_fd_name();
	my_socket->sema_name = s_get_sema_name();
	if (!my_socket->fd_name || !my_socket->sema_name)
		return (free(my_socket->fd_name), free(my_socket->sema_name), -1);
	my_socket->fd = open(my_socket->fd_name, O_CREAT | O_RDWR | O_TRUNC, 0640);
	if (my_socket->fd == -1)
		return (free(my_socket->fd_name), free(my_socket->sema_name), -1);
	sem_unlink(my_socket->sema_name);
	my_socket->sema = sem_open(my_socket->sema_name, O_CREAT, 0666, 0);
	if (my_socket->sema == SEM_FAILED)
		return (free(my_socket->fd_name), free(my_socket->sema_name),
			close(my_socket->fd), -1);
	if (malloc_read_fd(my_socket) == -1)
		return (sem_unlink(my_socket->sema_name), free(my_socket->fd_name),
			free(my_socket->sema_name), close(my_socket->fd),
			sem_close(my_socket->sema), -1);
	return (0);
}
