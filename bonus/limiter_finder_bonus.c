/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter_finder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:44 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/09 21:48:46 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(char *limiter)
{
	int		fd[2];
	char	*str;

	if (pipe(fd) == -1)
	{
		perror(NULL);
		exit(1);
	}
	while (1)
	{
		str = get_next_line(0);
		if (errno != 0)
		{
			close(fd[0]);
			close(fd[1]);
			perror("");
			exit(2);
		}
		if (ft_strncmp(limiter, str, ft_strlen(str) - 1) == 0)
			break ;
		write(fd[1], str, ft_strlen(str));
		free(str);
	}
	close(0);
	close(fd[1]);
	free(str);
	return (fd[0]);
}
