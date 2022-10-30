/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 13:59:49 by dapaulin         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size_str;

	size_str = ft_strlen(s);
	ptr = (char *) malloc(size_str * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size_str + 1);
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
	size_t	*c_pos;

	line_size = 0;
	while (1)
	{
		(*lst)-> content = ft_strdup(buf);
		c_pos = ft_strchr(buf )
		if (ft_strdup((*lst)-> content))
		{
			line_size = ft
			break ;
		}
		ft_lstadd_back(lst, ft_lstnew(NULL));
		(*lst) = (*lst)-> next;
		read(fd, buf, BUFFER_SIZE);
	}
}

size_t	check_static(int fd, t_list **lst)
{
	char		*c_pos;
	static char	buf[BUFFER_SIZE];
	
	c_pos = ft_strchr(buf, '\n');
	if (c_pos && (c_pos < BUFFER_SIZE))
		line_size = fill_list(fd, &buf[c_pos - buf + 1], &lst);
	else
	{
		read(fd, buf, BUFFER_SIZE);
		line_size = fill_list(fd, &buf, &lst);
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
	lst = ft_lstnew(NULL);
	if (!lst)
		return (NULL);
	line_size = check_static(fd, &lst);
	line = create_line(&lst, line_size);
	ft_lstclear(&ret, free);
	return (line);
}
