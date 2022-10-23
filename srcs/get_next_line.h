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

t_list		*ft_new(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_lst *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
char		*get_next_line(int fd);

#endif
