/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:30:17 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/09 22:15:34 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_bonus_H
# define GET_NEXT_LINE_bonus_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*get_strjoin(char const *s1, char const *s2);
char	*get_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*is_empty(char (*stash)[BUFFER_SIZE + 1]);
char	*get_next(int fd, char (*stash)[BUFFER_SIZE + 1], char *str, int *ret);
char	*set_stash(char *buf, char (*stash)[BUFFER_SIZE + 1], int *ret);

#endif
