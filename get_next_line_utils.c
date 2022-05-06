/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:34:46 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/29 18:01:45 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = s;
	while (*str != '\0' || *str == c)
	{
		if (*str == (char)c)
			return (str);
		++str;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest = malloc(sizeof(char));
		dest[i] = '\0';
		return (dest);
	}
	else if (len > ft_strlen(s) - start)
		j = ft_strlen(s) - start;
	else
		j = len;
	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (NULL);
	while (start < ft_strlen(s) && i < j)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
