/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:59:51 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 13:19:34 by geudes           ###   ########.fr       */
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

typedef struct s_data
{
	int		f;
	int		c;
	char	*no;
	char	*ea;
	char	*we;
	char	*so;
}	t_data;

// Parsing
int	parsing_color(char *line);
t_data	parsing_data(int fd);

int	wildcard(char *patern, char *str);
int	wildcard_nb(char *patern, char *str);
char	*gnl(int fd);
int	atouc(char	*str, int *rgb);
char	*ft_strdup(char *s);
int	ft_strlen(char *str);

#endif
