#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct a_list
{
	void		*content;
	struct a_list	*next;
}	t_list;
// String Manipulation
size_t 		ft_strlen(const char *str);
char		*ft_strchr(const char *src, int c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
// List Manipulation
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
// GNL Actions
char		*get_next_line(int fd);
#endif
