/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:17:32 by geudes            #+#    #+#             */
/*   Updated: 2023/08/24 17:24:43 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

void	my_socket_close(t_my_socket *my_socket)
{
	int	i;

	unlink(my_socket->fd_name);
	close(my_socket->fd);
	free(my_socket->fd_name);
	sem_close(my_socket->sema);
	sem_unlink(my_socket->sema_name);
	free(my_socket->sema_name);
	i = -1;
	while (++i < my_socket->nb_player)
	{
		if (my_socket->p_fd[i] >= 0)
			close (my_socket->p_fd[i]);
		unlink(my_socket->pfd_name[i]);
		free(my_socket->pfd_name[i]);
	}
}
