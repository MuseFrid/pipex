/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:47:52 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/13 17:31:00 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*free_access(char **tab, char *cmd)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	if (cmd)
		free(cmd);
	return (NULL);
}

static char	*access_path(char **which_path)
{
	int		i;
	char	*str;

	i = 0;
	while (which_path[i])
	{
		if (access(which_path[i], X_OK) == 0)
		{
			str = ft_strdup(which_path[i]);
			free_access(which_path, NULL);
			return (str);
		}
		i++;
	}
	free_access(which_path, NULL);
	return (NULL);
}

static char	*parse_extention(char **new_cmd, char **which_path, const char *cmd)
{	
	char	*save;

	*new_cmd = ft_strjoin("/", cmd);
	if (!*new_cmd)
		return (free_access(which_path, NULL));
	save = which_path[0];
	which_path[0] = ft_strdup((*which_path) + 5);
	free(save);
	if (!(which_path[0]))
		return (free_access(which_path, *new_cmd));
	return (*new_cmd);
}

char	*parse(char **envp, const char *cmd)
{
	int		i;
	char	**which_path;
	char	*new_cmd;
	char	*save;

	i = 0;
	new_cmd = NULL;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	which_path = ft_split(envp[i], ':');
	if (!which_path)
		return (NULL);
	i = -1;
	if (parse_extention(&new_cmd, which_path, cmd) == NULL)
		return (NULL);
	while (which_path[++i])
	{
		save = ft_strjoin(which_path[i], new_cmd);
		if (!save)
			return (free_access(which_path, new_cmd));
		which_path[i] = save;
	}
	free(new_cmd);
	return (access_path(which_path));
}
