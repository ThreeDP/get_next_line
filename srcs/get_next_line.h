/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:35 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/24 09:31:35 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef struct a_list
{
	char			*content;
	t_bool			end_line;
	struct a_list	*next;
}	t_list;

// String Manipulation
size_t 		ft_strlen(const char *str);
char		*ft_strchr(const char *src, int c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
// List Manipulation
t_list		*ft_lstnew(char *content, t_bool end_line);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
// GNL Actions
char		*get_next_line(int fd);
#endif
