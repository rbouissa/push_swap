/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:49 by rbouissa          #+#    #+#             */
/*   Updated: 2022/11/12 18:03:16 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allofit(int fd, char *str)
{
	char	*p;
	int		i;

	i = 1;
	p = malloc(BUFFER_SIZE + 1);
	if (!p)
		return (0);
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, p, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(p);
			return (0);
		}
		p[i] = '\0';
		str = ft_strjoin(str, p);
	}
	free(p);
	return (str);
}

char	*ft_lwl(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	p = malloc(i + 2);
	if (!p)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_rest(char *str)
{
	char	*p;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	len = ft_strlen(str) - i + 1;
	p = malloc(len);
	if (!p)
		return (NULL);
	i++;
	while (str[i])
		p[j++] = str[i++];
	free(str);
	p[j] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*lewl;
	char		*tani;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lewl = ft_allofit(fd, lewl);
	if (!lewl)
		return (0);
	tani = ft_lwl(lewl);
	lewl = ft_rest(lewl);
	return (tani);
}
