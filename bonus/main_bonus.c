/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:58 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/13 17:31:55 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	r;
	int	fd;

	r = 0;
	fd = -2;
	if (argv && envp && argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			fd = here_doc(argv[2]);
		r = hub_pipe(argc, argv, envp, fd);
		wait(NULL);
		if (r)
			return (r);
		return (0);
	}
	write(2, "Something wrong with arg !\n", 27);
	return (1);
}
