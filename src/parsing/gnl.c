/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:12:20 by geudes            #+#    #+#             */
/*   Updated: 2023/08/04 12:14:50 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free1(char *str1, char buff)
{
	char	*res;
	int		i;

	if (!str1)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (0);
		res[0] = buff;
		res[1] = 0;
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(str1) + 2));
	if (!res)
		return (free(str1), (char *)0);
	i = -1;
	while (str1[++i])
		res[i] = str1;
	res[i] = buff;
	res[i + 1] = 0;
	return (free(str1), res);
}

char	*gnl(int fd)
{
	char	*res;
	char	buff;
	int		br;

	br = read(fd, &buff, 1);
	res = 0;
	if (br == -1)
		return (0);
	if (br == 1 && buff != '\n')
		res = ft_strjoin_free1(0, buff);
	while (br && buff != '\n')
	{
		br = read(fd, &buff, 1);
		if (br == 1 && buff != '\n')
			res = ft_strjoin_free1(res, buff);
	}
	return (res);
}
