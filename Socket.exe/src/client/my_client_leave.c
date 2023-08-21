/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_leave.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:13:30 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 16:19:02 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

void	my_client_leave(t_my_client my_client)
{
	close(my_client.read_fd);
	free(my_client.rfd_name);
	sem_close(my_client.sema);
	free(my_client.sema_name);
	close(my_client.write_fd);
	free(my_client.wfd_name);
}
