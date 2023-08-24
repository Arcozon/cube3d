/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_post.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:14:32 by geudes            #+#    #+#             */
/*   Updated: 2023/08/24 17:20:30 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_socket_post(t_my_socket *my_socket)
{
	int	i;

	i = -1;
	while (++i < my_socket->nb_player)
		sem_post(my_socket->sema);
	return (0);
}
