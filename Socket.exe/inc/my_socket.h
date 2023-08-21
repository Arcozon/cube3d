/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   my_socket.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: geudes <geudes@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/08/19 00:41:55 by geudes			#+#	#+#			 */
/*   Updated: 2023/08/21 15:46:07 by geudes		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef MY_SOCKET_H
# define MY_SOCKET_H

// Create  a "Socket" to trade float/int/char in binary with other processes

# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define MAX_PLAYER 8
# define P_NAME_LEN 2

//				 -----	  SERVER	  -----
typedef struct s_my_socket
{
	int		nb_player;
	char	*fd_name;
	int		fd;
	char	*sema_name;
	sem_t	*sema;
	int		p_fd[MAX_PLAYER];
	char	*pfd_name[MAX_PLAYER];
}	t_my_socket;

int		my_socket_create(t_my_socket *my_socket, int nb_player);
void	my_socket_close(t_my_socket my_socket);

int		my_socket_reset(t_my_socket *my_socket);

int		my_socket_write_float(t_my_socket my_socket, float to_write);
int		my_socket_write_int(t_my_socket my_socket, int to_write);
int		my_socket_write_char(t_my_socket my_socket, char to_write);


char	*s_get_fd_name(void);
char	*s_get_sema_name(void);

//				 -----	  CLIENT	  -----
typedef struct s_my_client
{
	int		id_player;
	int		read_fd;
	char	*rfd_name;
	sem_t	*sema;
	char	*sema_name;
	int		write_fd;
	char	*wfd_name;
}	t_my_client;

int		my_client_join(t_my_client *my_client, char *user);
void	my_client_leave(t_my_client my_socket);
int		my_client_reset(t_my_client *my_client);


int		my_client_read_float(t_my_client my_socket, float *to_read);
int		my_client_read_int(t_my_client my_socket, int *to_read);
int		my_client_read_char(t_my_client my_socket, char *to_read);


char	*c_get_rfd_name(char *user);
char	*c_get_wfd_name(char *user, int id);
char	*c_get_sema_name(char *user);

// Utils
int		s_strlen(char *str);

#endif
