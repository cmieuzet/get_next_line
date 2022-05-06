/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:33:30 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/05/04 13:47:36 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_readfd(int fd, char *line)
{
	int		byte_check;
	char	*buffer;

	byte_check = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (byte_check != 0 && !ft_strchr(buffer, '\n'))
	{
		byte_check = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_check] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (byte_check == 0)
	{
		if (line)
			return (free(buffer), line);
		free(buffer);
		free(line);
		return (NULL);
	}
	free(buffer);
	return (line);
}

char	*ft_line_find(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = '\n';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_stash(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	i++;
	j = ft_strlen(str);
	j -= i;
	tmp = ft_substr(str, i, j);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*readfd;
	char		*line;
	static char	*stash;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
		return (free(buff), NULL);
	free(buff);
	if (!stash || !ft_strchr(stash, '\n'))
		readfd = ft_readfd(fd, stash);
	else
	{
		readfd = malloc(sizeof(char));
		if (!readfd)
			return (NULL);
		readfd[0] = '\0';
		readfd = ft_strjoin(readfd, stash);
		free(stash);
	}
	line = ft_line_find(readfd);
	stash = ft_stash(readfd);
	return (free(readfd), line);
}
