/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:55:56 by jocaetan          #+#    #+#             */
/*   Updated: 2021/11/18 14:32:21 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sublen;

	if (!s)
		return (NULL);
	if (ft_gnl_strlen(s) <= start)
		sublen = 0;
	else if (ft_gnl_strlen(s) <= len)
		sublen = ft_gnl_strlen(s) - start;
	else
		sublen = len;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < sublen)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (NULL);
	i = -1;
	ch = c;
	while (s[++i])
	{
		if (s[i] == ch)
		{
			i++;
			return ((char *)s + i);
		}
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_gnl_strdup(const char *s)
{
	int		i;
	char	*d;
	size_t	strlen;

	if (!s)
		return (NULL);
	i = -1;
	strlen = 0;
	while (s[++i])
		strlen++;
	d = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!d)
		return (NULL);
	i = -1;
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (ft_gnl_strdup(s1));
	if (!s1)
		return (ft_gnl_strdup(s2));
	len1 = ft_gnl_strlen(s1);
	len2 = ft_gnl_strlen(s2);
	s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		s[i] = s1[++j];
	j = -1;
	while (++j < len2)
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
