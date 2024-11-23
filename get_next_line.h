/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:38:30 by abougati          #+#    #+#             */
/*   Updated: 2024/11/23 16:28:12 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);
char	*read_and_add(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*adjust_buffer(char *buffer);
char	*helper(char **buffer);

int		check_for_endline(char *buff);
char	*copy(char *buffer, char *line, int i);
char	*ft_join(char *s1, char *s2);
char	*dupp(char *s);
int		get_len(char *s);

#endif
