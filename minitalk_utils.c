/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:09:47 by stissera          #+#    #+#             */
/*   Updated: 2022/04/01 09:33:37 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_itoa(pid_t pid)
{
	int		size;
	int		backup;
	char	*ret;

	size = 0;
	backup = (int)pid;
	while (pid > 0)
	{
		size++;
		pid /= 10;
	}
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	while (size-- != 0)
	{
		ret[size] = backup % 10 + 48;
		backup /= 10;
	}
	return (ret);
}

int	ft_atoi(const char *src)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (src[i])
	{
		ret *= 10;
		ret += src[i] - 48;
		i++;
	}
	return (ret);
}
