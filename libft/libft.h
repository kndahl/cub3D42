/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:46:18 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/12 21:53:54 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *str1, const char *str2, size_t len);
char			*ft_strrchr(const char *s, int ch);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int ch);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *str, int ch, size_t n);
void			*ft_memccpy(void *dst, const void *src, int ch, size_t num);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t number, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
int				ft_atoi(char *str);
int				ft_isalnum(int ch);
int				ft_isalpha(int ch);
int				ft_isdigit(int ch);
int				ft_isascii(int ch);
int				ft_isprint(int ch);
int				ft_memcmp(const void *s1, const void *s2, size_t num);
int				ft_strncmp(const char *s1, const char *s2, size_t num);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
int				ft_lstsize(t_list *lst);

#endif
