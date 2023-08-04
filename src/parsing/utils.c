/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geudes <geudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:43 by geudes            #+#    #+#             */
/*   Updated: 2023/08/04 12:56:45 by geudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wildcard(char *patern, char *str)
{
	if (!patern[0] && !str[0])
		return (1);
	if (patern[0] == '*')
		while (patern[1] == '*')
			patern++;
	if (patern[0] == '*' && patern[1] && !str[0])
		return (0);
	if (patern[0] == str[0])
		return (wildcard(patern + 1, str + 1));
	if (patern[0] == '*')
		return (wildcard(patern + 1, str) || wildcard(patern, str + 1));
	return (0);
}
