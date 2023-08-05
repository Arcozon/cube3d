/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:59:51 by geudes            #+#    #+#             */
/*   Updated: 2023/08/05 01:06:30 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define PATERN_C "C *,*,*"
# define PATERN_F "F *,*,*"
# define PATERN_NO "NO *"
# define PATERN_SO "SO *"
# define PATERN_EA "EA *"
# define PATERN_WE "WE *"

typedef struct s_data
{
	int		f;
	int		c;
	char	*no;
	char	*ea;
	char	*we;
	char	*so;
}	t_data;

#endif
