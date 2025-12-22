/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 08:05:25 by vcerny            #+#    #+#             */
/*   Updated: 2025-03-20 08:05:25 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr_gnl(const char *s, int c);
char	*ft_strsub_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strcpy_gnl(char *dest, const char *src);
void	ft_bzero_gnl(void *s, size_t n);
int		ft_strlen_gnl(const char *string);
char	*get_next_line(int fd);

#endif
