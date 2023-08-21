/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:36:13 by geudes            #+#    #+#             */
/*   Updated: 2023/08/21 19:43:34 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.h"

void	client(void)
{
	t_my_client	my_client;
	float		my_float;

	if (my_client_join(&my_client, getenv("USER")))
		return ;
	my_client_read_float(my_client, &my_float);
	printf("%f\n", my_float);
	my_client_reset(&my_client);
	my_client_read_float(my_client, &my_float);
	printf("%f\n", my_float);
	my_client_leave(my_client);
}

void	socket(void)
{
	t_my_socket	my_socket;

	if (my_socket_create(&my_socket, 2))
		return ;
	my_socket_write_float(my_socket, 1.012514f);
	my_socket_reset(&my_socket);
	my_socket_write_float(my_socket, 1.0114f);
	my_socket_close(my_socket);
}

int	main(int ac, char **av, char **envp)
{
	int	pid[9];

	((void)ac, (void)av, (void)envp);
	pid[0] = fork();
	if (pid[0] == 0)
		return (socket(), 0);
	pid[1] = fork();
	if (pid[1] == 0)
		return (client(), 0);
	pid[2] = fork();
	if (pid[2] == 0)
		return (client(), 0);
	for (int i = 0; i < 3; i++)
		waitpid(pid[i], 0, 0);
	return (0);
}
