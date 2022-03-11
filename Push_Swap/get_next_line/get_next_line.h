/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:29:07 by jocaetan          #+#    #+#             */
/*   Updated: 2021/11/18 14:36:15 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strdup(const char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(const char *str);
char	*get_next_line(int fd);

#endif
