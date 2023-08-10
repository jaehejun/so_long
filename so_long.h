/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:18:11 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/10 19:23:54 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "./mlx/mlx.h"

# define BUFFER_SIZE 100

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*free_memory(char *allocated1, char *allocated2);
char	*get_next_line(int fd);
char	*read_line(int fd, char *remain);
char	*make_line(char *temp_read);
char	*make_remain(char *temp_read);

int		count_single(const char *s, char c);
char	*single(const char *s, char c);
void	free_all(char **str, int index);
char	**ft_split(char const *s, char c);

#endif
