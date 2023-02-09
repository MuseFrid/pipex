/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:15 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/09 21:48:17 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	gd_error(int pick)
{
	int			i;
	static char	*error[] = {
		"Error\nOpen failed\n",
		"Error\nClose failded\n",
		"Error\nMalloc failed\n",
		"Error\nPipe failed\n"};

	i = 0;
	if (errno != 0)
		perror(NULL);
	else if (!(pick == -1))
		while (error[pick][i])
			write (2, &error[pick][i++], 1);
}
