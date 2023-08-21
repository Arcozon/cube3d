/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:49:52 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 19:27:48 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

static int	join_self_file(t_my_client *my_client, char *user)
{
	my_client->id_player = 0;
	my_client->wfd_name = 0;
	my_client->write_fd = -1;
	while (my_client->write_fd == -1 && my_client->id_player < MAX_PLAYER)
	{
		my_client->wfd_name = (free(my_client->wfd_name),
				c_get_wfd_name(user, my_client->id_player));
		my_client->write_fd = open(my_client->wfd_name,
				O_CREAT | O_WRONLY | O_TRUNC | O_EXCL, 0640);
		my_client->id_player++;
	}
	if (my_client->write_fd == -1 || my_client->id_player >= MAX_PLAYER)
		return (free(my_client->wfd_name), close(my_client->write_fd), -1);
	return (0);
}

int	my_client_join(t_my_client *my_client, char *user)
{
	my_client->rfd_name = c_get_rfd_name(user);
	my_client->sema_name = c_get_sema_name(user);
	if (!my_client->rfd_name || !my_client->sema_name)
		return (free(my_client->rfd_name), free(my_client->sema_name), -1);
	my_client->read_fd = open(my_client->rfd_name, O_RDWR);
	if (my_client->read_fd == -1)
		return (free(my_client->rfd_name), free(my_client->sema_name), -1);
	my_client->sema = sem_open(my_client->sema_name, 0);
	if (my_client->sema == SEM_FAILED)
		return (free(my_client->rfd_name), free(my_client->sema_name),
			close(my_client->read_fd), -1);
	if (join_self_file(my_client, user))
		return (free(my_client->rfd_name), free(my_client->sema_name),
			close(my_client->read_fd), sem_close(my_client->sema), -1);
	return (0);
}
