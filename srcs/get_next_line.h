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

char	*get_next_line(int fd);

#endif
