/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:36:32 by ethanlim          #+#    #+#             */
/*   Updated: 2024/12/05 16:45:44 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char *s);
int		total_size(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_getline(char *stash);
char	*ft_readfile(int fd, char *stash);
char	*ft_strjoin_free(char *s1, char *s2);
char	*process_stash(char *stash);
int		ft_strchr(char *str, int c);
void	*ft_calloc(size_t num, size_t size);
#endif