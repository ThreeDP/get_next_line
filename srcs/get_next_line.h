/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:35 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/06 19:35:37 by dapaulin         ###   ########.fr       */
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
	struct a_list	*next;
}	t_list;

// String Manipulation
size_t		get_strlen(const char *str);
char		*get_strchr(const char *src, int c);
size_t		get_strlcpy(char *dest, const char *src, size_t size);
size_t		get_strlcat(char *dst, const char *src, size_t size);
char		*get_strdup(const char *s, size_t size);
// List Manipulation
t_list		*get_lstnew(char *content);
void		get_lstadd_back(t_list **lst, int creat_lst);
void		get_lstclear(t_list **lst, void (*del)(void *));
// GNL Actions
char		*get_next_line(int fd);
#endif
