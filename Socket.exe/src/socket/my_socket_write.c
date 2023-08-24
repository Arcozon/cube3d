/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:35:45 by geudes            #+#    #+#             */
/*   Updated: 2023/08/24 17:51:01 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

int	my_socket_write_float(t_my_socket my_socket, float to_write)
{
	uint	to_write_uint;
	char	my_char;
	int		i;

	to_write_uint = *(uint *)&to_write;
	i = 32;
	while (--i >= 0)
	{
		my_char = '0' + (to_write_uint >> i & 1);
		write(my_socket.fd, &my_char, 1);
	}
	write(my_socket.fd, "\n", 1);
	return (1);
}

int	my_socket_write_int(t_my_socket my_socket, int to_write)
{
	char	my_char;
	int		i;

	i = 32;
	while (--i >= 0)
	{
		my_char = '0' + (to_write >> i & 1);
		write(my_socket.fd, &my_char, 1);
	}
	write(my_socket.fd, "\n", 1);
	return (1);
}

int	my_socket_write_char(t_my_socket my_socket, char to_write)
{
	char	my_char;
	int		i;

	i = 8;
	while (--i >= 0)
	{
		my_char = '0' + (to_write >> i & 1);
		write(my_socket.fd, &my_char, 1);
	}
	write(my_socket.fd, "\n", 1);
	return (1);
}
