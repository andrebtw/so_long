/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:33 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/13 08:43:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// SIGNALS //
# define NOT_READ -10

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	strlen_gnl(const char *s, int check_if_endl);
void	failed_malloc(char *temp_string, char *r_string);
char	*static_init(int free_static, char *savd_s, char *r_s, char *temp_s);

#endif
