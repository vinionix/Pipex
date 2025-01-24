/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:29:57 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/23 16:48:24 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t num, size_t size);

void				ft_free(char **var);

int					ft_isalnum(int c);

int					ft_isalpha(int ch);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

void				*ft_memchr(const void *arr, int chr, size_t num);

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *string, int character, size_t num);

char				*ft_strdup(const char *str);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);

size_t				ft_strlen(const char *str);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *str, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_itoa(int n);

char				**ft_split(char const *s, char c);

char				*ft_strtrim(char const *s1, char const *set);

void				ft_putchar_fd(char c, int fd);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

t_list				*ft_lstlast(t_list *lst);

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
