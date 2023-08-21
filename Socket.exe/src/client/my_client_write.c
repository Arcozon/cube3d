/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:22:40 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 19:26:09 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_client_write(t_my_client my_client, char c)
{
	write(my_client.write_fd, &c, 1);
	return (0);
}
