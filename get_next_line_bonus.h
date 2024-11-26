/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:31 by abougati          #+#    #+#             */
/*   Updated: 2024/11/26 12:08:10 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*read_and_add(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*adjust_buffer(char *buffer);
char	*helper(char **buffer);

int		check_for_endline(char *buff);
char	*copy(char *buffer, char *line, int i);
char	*ft_join(char **s1, char *s2);
char	*dupp(char *s);
int		get_len(char *s);

#endif
