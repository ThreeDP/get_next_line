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
size_t	make_pieces(int fd, char *buffer, t_list **lst)
{
	size_t	line_size;
	char	*c_pos;
	t_list	*list;
	size_t	bsr;
	char	tmp[BUFFER_SIZE];

	list = *lst;
	line_size = 0;
	while (1)
	{
		c_pos = ft_strchr(buffer, '\n');
		if (c_pos)
		{
			list-> content = ft_strdup(buffer, (c_pos - buffer) + 1);
			ft_strlcpy(tmp, &buffer[(c_pos - buffer) + 1], BUFFER_SIZE);
			ft_strlcpy(buffer, tmp, ft_strlen(tmp) + 1);
			return (line_size += (c_pos - buffer) + 1);
		}
		line_size += list-> bsr;
		list-> content = ft_strdup(buffer, list-> bsr);
		bsr = read(fd, buffer, BUFFER_SIZE);
		buffer[bsr] = '\0';
		if (!bsr)
			return (line_size);
		ft_lstadd_back(&list, ft_lstnew(NULL, 0));
		list = list-> next;
		list-> bsr = bsr;
	}
	return (0);
}

/* 
check if the buffer is empty and set the bsr	*/
void	check_static(int fd, char *buffer, t_list **lst)
{
	if (!ft_strlen(buffer))
	{
		(*lst)-> bsr = read(fd, buffer, BUFFER_SIZE);
		buffer[(*lst)-> bsr] = '\0';
	}
	else
		(*lst)-> bsr = ft_strlen(buffer);
}

char	*get_next_line(int fd)
{
	t_list		*lst;
	char		*line;
	size_t		line_size;
	static char	buf[BUFFER_SIZE];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	lst = ft_lstnew(NULL, 0);
	if (!lst)
		return (NULL);
	check_static(fd, buf, &lst);
	line_size = make_pieces(fd, buf, &lst);
	if (line_size)
		line = create_line(&lst, line_size);
	ft_lstclear(&lst, free);
	return (line);
}
