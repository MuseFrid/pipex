/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_pipe_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:32 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/13 11:42:21 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	process_error(int fd_in, int fd, char **cmd)
{
	int	i;

	i = 0;
	if (fd_in != -1)
		close(fd_in);
	if (fd != -1)
		close(fd);
	if (errno != 0)
		perror(NULL);
	if (cmd)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}
	return (-1);
}

int	process(char *argv, char **envp, int fd_in, int fd[2])
{
	char	**cmd;
	char	*path;

	if (fork() == 0)
	{
		close(fd[0]);
		if (dup2(fd_in, 0) == -1 || dup2(fd[1], 1) == -1)
			return (process_error(fd_in, fd[1], NULL));
		cmd = ft_split(argv, ' ');
		if (!cmd)
			return (process_error(fd_in, fd[1], NULL));
		path = parse(envp, cmd[0]);
		if (!path)
			return (process_error(fd_in, fd[1], cmd));
		execve(path, cmd, envp);
		free(path);
		return (process_error(fd_in, fd[1], cmd));
	}
	if (errno != 0)
		return (process_error(fd_in, fd[1], NULL));
	process_error(fd_in, fd[1], NULL);
	return (fd[0]);
}

void	create_file(int fd_pipe[2], int bol, int fd, char *argv)
{
	if (bol)
		fd_pipe[1] = open(argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd_pipe[1] = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_pipe[1] == -1)
	{
		perror(NULL);
		close(fd);
		exit(17);
	}
	fd_pipe[0] = -2;
}

static void	outfile_to_fd_pipe(int outfile_fd[2], int (*fd_pipe)[2])
{
	(*fd_pipe)[0] = outfile_fd[0];
	(*fd_pipe)[1] = outfile_fd[1];
}

int	hub_pipe(int argc, char **argv, char **envp, int fd)
{
	int	i;
	int	fd_pipe[2];
	int	outfile_fd[2];

	i = 2;
	if (fd == -2)
		fd = open(argv[i - 1], O_RDONLY);
	else
		i++;
	create_file(outfile_fd, i - 2, fd, argv[argc - 1]);
	if (fd == -1)
		error_exit();
	fd_pipe[0] = 0;
	while (fd_pipe[0] != -2)
	{
		if (i == argc - 2)
			outfile_to_fd_pipe(outfile_fd, &fd_pipe);
		else if (pipe(fd_pipe) == -1)
			return (process_error(fd, -1, NULL));
		fd = process(argv[i++], envp, fd, fd_pipe);
		if (fd == -1)
			return (4);
	}
	return (0);
}
