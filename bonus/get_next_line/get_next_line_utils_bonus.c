/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:37:49 by gduchesn          #+#    #+#             */
/*   Updated: 2023/02/09 22:15:52 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_strjoin(char const *s1, char const *s2)
{
	char	*strfinal;
	int		i;
	int		j;

	if (!s1 && s2)
		return (get_strdup(s2));
	if (s1 && !s2)
		return (get_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	strfinal = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!strfinal)
		return (NULL);
	i = -1;
	while (s1[++i])
		strfinal[i] = s1[i];
	j = 0;
	while (s2[j])
		strfinal[i++] = s2[j++];
	strfinal[i] = 0;
	return (strfinal);
}

char	*get_strdup(const char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char *) s;
	i = ft_strlen(new);
	if ((size_t) start > i)
		return (get_strdup(""));
	if (i < len)
		return (get_strdup((char *) s + start));
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (start >= i)
		return (new);
	i = 0;
	while (i < len)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}
