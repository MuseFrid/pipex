/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:17:58 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/13 11:40:24 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "get_next_line/get_next_line_bonus.h"

void	error_exit(void);
char	**ft_split(char const *s, char c);
char	*parse(char **envp, const char *cmd);
char	*free_access(char **tab, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		hub_pipe(int argc, char **argv, char **envp, int fd);
int		error_init(char *before, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int		here_doc(char *limiter);

#endif
