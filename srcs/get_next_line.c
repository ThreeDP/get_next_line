/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/09 20:28:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlen(const char *str)
{
	int size;
	
	size = 0;
	while (str[size])
		size++;
	return (size);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	char	*cached_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	cached_src = (char *)src;
	if (size <= len_dst)
		return (size + len_src);
	while (cached_src[i] && (len_dst + 1) < size)
		dst[len_dst++] = cached_src[i++];
	dst[len_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&cached_src[i]));
}

char	*ft_strdup(const char *s)
{
	char 	*ptr;
	size_t	size_str;

	size_str = ft_strlen(s);
	ptr = (char *) malloc(size_str * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size_str + 1);
	return(ptr);
}

size_t	make_line(int fd, char *buffer, t_list **lst)
{
//	size_t	buf_size;
	size_t	ptr_size;
	char	*pos_c;

	ptr_size = 0;
	while (1)
	{
		if (*buffer != '\n')
			read(fd, buffer, BUFFER_SIZE);
		else
			buffer++;
		pos_c = ft_strchr(buffer, '\n');
		(*lst) -> content = ft_strdup(buffer);
		if (pos_c)
		{
			((char *)(*lst) -> content)[pos_c - buffer + 1] = '\0';
			break ;
		}
		ptr_size += ft_strlen((*lst) -> content);
		ft_lstadd_back(lst, ft_lstnew(NULL));
		(*lst) = (*lst) -> next;
	}
	return (ptr_size + ft_strlen((*lst) -> content));
}

char	*get_next_line(int fd)
{
	static	char 	buf[BUFFER_SIZE];
	t_list		*lst;
	t_list		*ret;
	char		*line;
	size_t		line_size;

	lst = ft_lstnew(NULL);
	ret = lst;
	line_size = make_line(fd, buf, &lst);
	line = (char *) calloc(line_size + 1, sizeof(char));
	lst = ret;
	while (lst)
	{
		ft_strlcat(line, lst -> content, line_size + 1);
		lst = lst -> next;
	}
	ft_lstclear(&ret, free);
	return (line);
}
