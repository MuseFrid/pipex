/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:49:57 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/13 15:34:35 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	r;

	r = 0;
	if (argv && envp && argc == 5)
	{
		r = hub_pipe(argc, argv, envp);
		wait(NULL);
		if (r)
			return (r);
		return (0);
	}
	write(2, "Something wrong with arg !\n", 27);
	return (1);
}
