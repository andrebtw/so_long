/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:46:40 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/24 13:04:08 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

// Convertion //
// atoi : Converts a string to an int
int		ft_atoi(const char *nptr);
// itoa : Converts an int to an alloced string
char	*ft_itoa(int n);

// Memory initialisation //
// bzero : Puts '\0's everywhere in pointer
void	ft_bzero(void *s, size_t n);
// calloc : Allocates memory and puts '\0's everywhere in pointer
void	*ft_calloc(size_t count, size_t size);
// strdup : Allocates and creates a copy of the string in arg
char	*ft_strdup(const char *s);

// Character checking //
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// Character transformation
int		ft_tolower(int c);
int		ft_toupper(int c);

// Memory manipulation //
// memchr : scans the string until it finds character in n chars
void	*ft_memchr(const void *s, int c, size_t n);
// memcmp : scans both strings until in finds a diff in n chars
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// memcpy : copies memory from src to dest in n memory
void	*ft_memcpy(void *dest, const void *src, size_t n);
// memmove : copies memory from src to dest in n memory and overlap security
void	*ft_memmove(void *dest, const void *src, size_t n);
// memset :  Sets a constant value to the whole pointer in n memory
void	*ft_memset(void *s, int c, size_t n);

// String manipulation //
// strjoin : joins both strings ; ex : "hello", "world" ; value : "helloworld"
char	*ft_strjoin(char const *s1, char const *s2);
// strlcat : appends src to the end of dst. 
// It will append at most size - strlen(dst) - 1 bytes
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// strlen : size of string
size_t	ft_strlen(const char *s);
// strncmp : compares both strings in n chars
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// strncpy : copies string from src to dest in n chars
char	*ft_strncpy(char *dest, const char *src, size_t n);
// strnstr : Locates the first occurence of the
// string needle in haystack in n chars
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
// strrchr : Finds the last occurence of the char c in the string
char	*ft_strrchr(const char *s, int c);
// substr : Returns a string that starts from index
// start until len chars from the string s
char	*ft_substr(char const *s, unsigned int start, size_t len);
// strchr : Finds the first occurence of the char c in the string
char	*ft_strchr(const char *s, int c);
// strlcpy : copies up to dstsize - 1 chars
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// strtrim : trims the char with the char set
char	*ft_strtrim(char const *s1, char const *set);
// split : splits the string with the separator into multiple strings
char	**ft_split(char const *s, char c);

// Write functions //
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Function pointers //
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// ---BONUS--- //
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif