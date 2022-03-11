/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:49:21 by jocaetan          #+#    #+#             */
/*   Updated: 2021/11/18 14:36:27 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024

char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strdup(const char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(const char *str);
char	*get_next_line(int fd);

#endif
