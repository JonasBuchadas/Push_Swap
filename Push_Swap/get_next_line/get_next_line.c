/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:34:09 by jocaetan          #+#    #+#             */
/*   Updated: 2021/11/18 14:29:54 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line(char *str);
static char	*remove_line(char *str);
static char	*get_next_buffer(int fd);
static char	*join_until_nl(int fd, char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*next;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next = get_next_buffer(fd);
	temp = str;
	if (temp)
		str = ft_gnl_strjoin(temp, next);
	else
		str = ft_gnl_strjoin(NULL, next);
	if (next)
		free(next);
	if (temp)
		free(temp);
	if (!str)
		return (NULL);
	if (!ft_gnl_strchr(str, '\n'))
		str = join_until_nl(fd, str);
	temp = ft_gnl_strdup(str);
	str = remove_line(str);
	return (line(temp));
}

static char	*get_next_buffer(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0 || bytes > BUFFER_SIZE)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

static char	*join_until_nl(int fd, char *str)
{
	char	*temp;
	char	*next;

	next = get_next_buffer(fd);
	if (!next)
		return (str);
	while (!ft_gnl_strchr(next, '\n'))
	{
		temp = str;
		str = ft_gnl_strjoin(temp, next);
		if (next)
			free (next);
		if (temp)
			free (temp);
		next = get_next_buffer(fd);
		if (!next)
			return (str);
	}
	temp = str;
	str = ft_gnl_strjoin(temp, next);
	if (next)
		free(next);
	if (temp)
		free(temp);
	return (str);
}

static char	*remove_line(char *str)
{
	size_t	strlen;
	size_t	linelen;
	char	*new_str;

	if (!str)
		return (NULL);
	strlen = ft_gnl_strlen(str);
	linelen = -1;
	while (str[++linelen])
	{
		if (str[linelen] == '\n')
		{
			linelen++;
			break ;
		}
	}
	new_str = ft_gnl_substr(str, linelen, (strlen - linelen));
	if (new_str[0] == '\0')
	{
		free(new_str);
		free(str);
		return (NULL);
	}
	free(str);
	return (new_str);
}

static char	*line(char *str)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = -1;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[++len])
	{
		if (str[len] == '\n')
		{
			len++;
			break ;
		}
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		line[i] = str[i];
	line[i] = '\0';
	free (str);
	return (line);
}
