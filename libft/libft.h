/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:19:47 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 17:17:45 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_abs(int n);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *nbr);
char		*ft_strchr(char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *source, size_t n);
void		*ft_memchr(void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dest, const void *source, size_t len);
size_t		ft_strlcpy(char *dest, const char *source, size_t dest_size);
size_t		ft_strlcat(char *dest, const char *source, size_t dest_size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
/** Bonuses **/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));

/***********************	GET_NEXT_LINE	*****************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_nl(int fd);
void	move_remains(char *str, int pos);
int		ft_strlen_gnl(char *str, int *end_flag);
char	*ft_calloc_gnl(size_t n_elements, size_t size);
char	*ft_strdup_gnl(char *src, int len_stash);
void	ft_strlcpy_gnl(char *dst, char *src, int size);

#endif
