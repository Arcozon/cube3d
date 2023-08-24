/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:03:05 by geudes            #+#    #+#             */
/*   Updated: 2023/08/24 17:22:47 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_socket_wait(t_my_socket *my_socket)
{
	int	i;

	i = 0;
	while (i < my_socket->nb_player)
	{
		my_socket->p_fd[i] = open(my_socket->pfd_name[i], O_RDONLY);
		if (my_socket->p_fd[i] == -1)
		{
			usleep(5000);
			continue ;
		}
		i++;
	}
	return (0);
}
