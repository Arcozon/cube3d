/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:59:51 by geudes            #+#    #+#             */
/*   Updated: 2023/08/08 18:18:34 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define PATERN_C "C ???,???,???"
# define PATERN_F "F ???,???,???"
# define PATERN_NO "NO *.xpm"
# define PATERN_SO "SO *.xpm"
# define PATERN_EA "EA *.xpm"
# define PATERN_WE "WE *.xpm"

# define USED_CHAR " 01EWSN"
# define USED_PLAYER "EWSN"
# define WALL '1'
# define EMPTY '0'
# define NOT_NEXT_EMPTY ' '

typedef struct s_data
{
	int		f;
	int		c;
	char	*no;
	char	*ea;
	char	*we;
	char	*so;
}	t_data;

typedef struct s_l_map
{
	char			*line;
	struct s_l_map	*next;
}	t_l_map;

// Parsing
int			parsing_color(char *line, t_data data, int fd, int old);
void		parsing_data2(int fd, t_data *data, char *line);
t_data		parsing_data(int fd);
void		free_data(t_data data);
void		free_data_line(t_data data, char *line, int fd, char *error);
t_data		init_data(void);
int			is_not_empty(char *line);
int			is_data_full(t_data data);
t_l_map		*get_l_map(int fd);
int			check_border(char **map);
void		*free_map(char **map);
int			check_player(char **map);
void		free_l_map(t_l_map *l_map);
char		**map_bs(int fd);

int			wildcard(char *patern, char *str);
int			wildcard_nb(char *patern, char *str);
char		*gnl(int fd);
int			atouc(char	*str, int *rgb, int last);
char		*ft_strdup(char *s);
int			ft_strlen(char *str);
void		*ft_calloc(int size);

#endif
