/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:12:31 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 19:30:36 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_client_reset(t_my_client *my_client)
{
	close(my_client->write_fd);
	my_client->write_fd = open(my_client->wfd_name,
			O_CREAT | O_WRONLY | O_TRUNC, 0640);
	if (my_client->write_fd == -1)
		(my_client_leave(*my_client), exit(2));
	return (lseek(my_client->read_fd, SEEK_SET, 0));
}
