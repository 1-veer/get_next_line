/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:11:46 by abougati          #+#    #+#             */
/*   Updated: 2024/11/26 12:09:14 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_for_endline(char *buff)
{
	int	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i])
	{
		if (buff[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*copy(char *buffer, char *line, int i)
{
	int	x;

	if (!buffer || !line)
		return (NULL);
	x = 0;
	while (buffer[x] && i > 0)
	{
		line[x] = buffer[x];
		x++;
		i--;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_join(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!*s1 && !s2)
		return (NULL);
	if (!*s1)
		return (dupp(s2));
	if (!s2)
		return (dupp(*s1));
	str = malloc(sizeof(char) * (get_len(*s1) + get_len(s2) + 1));
	if (!str)
		return (helper(s1));
	i = 0;
	j = 0;
	while ((*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(*s1);
	return (str);
}

char	*dupp(char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = get_len(s);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str = copy(s, str, i);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	get_len(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
