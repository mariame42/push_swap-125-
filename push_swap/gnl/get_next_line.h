/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:24:20 by meid              #+#    #+#             */
/*   Updated: 2024/11/26 08:25:06 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr_allocation(char *line, int len);
char	*ft_strchar_rev(char *line, int c);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_strchr(char *line, int c);
char	*ready_for_next(char *line);
char	*read_line(char *line, int fd);
char	*clean_line(char *line);
char	*ready_for_next(char *line);

#endif