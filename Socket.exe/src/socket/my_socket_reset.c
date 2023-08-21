/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:25:20 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 19:00:31 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_socket_reset(t_my_socket *my_socket)
{
	close(my_socket->fd);
	my_socket->fd = open(my_socket->fd_name, O_RDWR | O_TRUNC);
	if (my_socket->fd == -1)
		return (-1);
	return (0);
}
