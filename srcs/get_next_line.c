/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 16:51:56 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < (size -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	char	*cached_src;

	i = 0;
	len_dst = ft_strlen(dst);
	cached_src = (char *)src;
	if (size <= len_dst)
		return (0);
	while (cached_src[i] && (len_dst + 1) < size)
		dst[len_dst++] = cached_src[i++];
	dst[len_dst] = '\0';
	return (0);
}

char	*ft_strdup(const char *s, size_t size)
{
	char	*ptr;

	ptr = (char *) calloc(size + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size + 1);
	return (ptr);
}

/*
Copy the structure data to a single array
and return the line.						*/
char	*create_line(t_list **lst, size_t line_size)
{
	char	*line;
	t_list	*list;
	
	list  = *lst;
	line = (char *) calloc(line_size + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (list)
	{
		ft_strlcat(line, list-> content, line_size + 1);
		list = list-> next;
	}
	return (line);
}

/*
Populate and create new nodes with characters from
the file while not finding a \n character or the
end of the file			*/
size_t	fill_list(int fd, char *buf, t_list **lst)
{
	size_t	line_size;
	char	*c_pos;
	char	find_c;
	t_list	*list;
	size_t	last_size;

	list = *lst;
	line_size = 0;
	last_size = 0;
	find_c = '\n';
	if (!list-> buf_read)
		return (0);
	while (1)
	{
		if (list-> buf_read < BUFFER_SIZE && !ft_strchr(buf, find_c))
			find_c = '\0';
		c_pos = ft_strchr(buf, find_c);
		if (c_pos && (find_c == '\n' || find_c == '\0'))
		{
			buf[list-> buf_read] = '\0';
			if (find_c == '\n')
				last_size = (c_pos - buf) + 1;
			else if (find_c == '\0')
				last_size = list-> buf_read;
			list-> content = ft_strdup(buf, last_size);
			return (line_size += last_size);
		}
		line_size += list-> buf_read;
		list-> content = ft_strdup(buf, list-> buf_read);
		ft_lstadd_back(&list, ft_lstnew(NULL, 0));
		list = list-> next;
		list-> buf_read = read(fd, buf, BUFFER_SIZE);
	}
	return (0);
}

size_t	check_static(int fd, t_list **lst)
{
	char		*c_pos;
	size_t		line_size;
	t_list		*list;
	static char	buf[BUFFER_SIZE];
	
	list = *lst;
	c_pos = ft_strchr(buf, '\n');
	if (c_pos && ((c_pos - buf) < BUFFER_SIZE))
	{
		list-> buf_read = c_pos - buf;
		line_size = fill_list(fd, &buf[c_pos - buf + 1], &list);
	}
	else
	{
		list-> buf_read = read(fd, buf, BUFFER_SIZE);
		line_size = fill_list(fd, buf, &list);
	}
	return (line_size);
}

char	*get_next_line(int fd)
{
	t_list		*lst;
	char		*line;
	size_t		line_size;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	lst = ft_lstnew(NULL, 0);
	if (!lst)
		return (NULL);
	line_size = check_static(fd, &lst);
	if (line_size)
		line = create_line(&lst, line_size);
	ft_lstclear(&lst, free);
	return (line);
}
