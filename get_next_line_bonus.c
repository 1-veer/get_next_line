/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:13 by abougati          #+#    #+#             */
/*   Updated: 2024/11/28 11:50:28 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*my_line;

	if (fd > MAX_FD)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (helper(&buffer[fd]));
	buffer[fd] = read_and_add(fd, buffer[fd]);
	if (!buffer[fd])
		return (helper(&buffer[fd]));
	my_line = extract_line(buffer[fd]);
	buffer[fd] = adjust_buffer(buffer[fd]);
	return (my_line);
}

char	*read_and_add(int fd, char *buffer)
{
	int		bytes_read;
	char	*read_buff;

	read_buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buff)
		return (NULL);
	bytes_read = 1;
	while (!check_for_endline(buffer) && bytes_read > 0)
	{
		bytes_read = read(fd, read_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buff);
			return (helper(&buffer));
		}
		if (bytes_read == 0)
			break ;
		read_buff[bytes_read] = '\0';
		buffer = ft_join(&buffer, read_buff);
	}
	return (free(read_buff), buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	line = copy(buffer, line, i);
	return (line);
}

char	*adjust_buffer(char *buffer)
{
	char	*whats_left;
	int		i;
	int		j;

	if (!buffer || !*buffer)
		return (helper(&buffer));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
		j++;
	if (j == 0)
		return (helper(&buffer));
	whats_left = (char *)malloc(j + 1);
	if (!whats_left)
		return (helper(&buffer));
	whats_left = copy(buffer + i, whats_left, j);
	free(buffer);
	return (whats_left);
}

char	*helper(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}
