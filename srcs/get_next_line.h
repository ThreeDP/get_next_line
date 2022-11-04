/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:35 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 16:44:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct a_list
{
	char			*content;
	size_t			buf_read;
	struct a_list	*next;
}	t_list;

// String Manipulation
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *src, int c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s, size_t size);
// List Manipulation
t_list		*ft_lstnew(char *content, size_t buf_read);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
// GNL Actions
char		*get_next_line(int fd);
size_t		fill_list(int fd, char *buf, t_list **lst);
void		check_static(int fd, char *buffer, t_list **lst);
char		*create_line(t_list **lst, size_t line_size);
#endif
