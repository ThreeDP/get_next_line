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

	ptr = (char *) malloc(size * sizeof(char) + 1);
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
	
	line = (char *) calloc(line_size + 1, sizeof(char));
	if (!line)
		return (NULL);
	while ((*lst))
	{
		ft_strlcat(line, (*lst)-> content, line_size + 1);
		(*lst) = (*lst)-> next;
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
	size_t	buf_z;
	char	*c_pos;

	line_size = 0;
	while (1)
	{
		c_pos = ft_strchr(buf, '\n');
		if (c_pos)
		{
			(*lst)-> content = ft_strdup(buf, (c_pos - buf) + 1);
			line_size += (c_pos - buf) + 1;
			break ;
		}
		printf("\n%zu\t%s", line_size, buf);
		if ((*lst) -> buf_read < BUFFER_SIZE)
			break ;
		buf_z = ft_strlen(buf);
		(*lst)-> content = ft_strdup(buf, buf_z);
//		printf("\n%zu\t%s", line_size, (*lst)-> content);
		line_size += buf_z;
//		if ((*lst) -> buf_read < BUFFER_SIZE)
//			break ;
		ft_lstadd_back(lst, ft_lstnew(NULL, 0));
		(*lst) = (*lst)-> next;
		(*lst)-> buf_read = read(fd, buf, BUFFER_SIZE);
//		printf("\n%zu\t%s\t%s", (*lst)-> buf_read, buf, (*lst)-> content);
	}
	return (line_size);
}

size_t	check_static(int fd, t_list **lst)
{
	char		*c_pos;
	size_t		line_size;
	static char	buf[BUFFER_SIZE];
	
	c_pos = ft_strchr(buf, '\n');
	if (c_pos && ((c_pos - buf) < BUFFER_SIZE))
	{
		(*lst)-> buf_read = BUFFER_SIZE;
		line_size = fill_list(fd, &buf[c_pos - buf + 1], lst);
	}
	else
	{
		(*lst)-> buf_read = read(fd, buf, BUFFER_SIZE);
		line_size = fill_list(fd, buf, lst);
	}
	return (line_size);
}

char	*get_next_line(int fd)
{
	t_list		*lst;
	char		*line;
	size_t		line_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	lst = ft_lstnew(NULL, 0);
	if (!lst)
		return (NULL);
	line_size = check_static(fd, &lst);
	line = create_line(&lst, line_size);
	ft_lstclear(&lst, free);
	return (line);
}
