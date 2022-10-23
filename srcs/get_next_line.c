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

char	*get_next_line(int fd)
{
	char 	put_buffer[BUFFER_SIZE];
	t_list	*lst;
	t_list	*ret;
	char	*ptr;
	size_t		i;
	char	*s_pos;

	i = 0;
	lst = ft_lstnew(NULL);
	ret = lst;
	while (i < 100)
	{
		read(fd, put_buffer, BUFFER_SIZE);
		s_pos = ft_strchr(put_buffer, '\n');
		if (s_pos)
		{
			put_buffer[s_pos - put_buffer + 1] = '\0';
			lst -> content = ft_strdup(put_buffer);
			i += ft_strlen(put_buffer);
			break ;
		}
		lst -> content = ft_strdup(put_buffer);
		i += ft_strlen(lst -> content);
		ft_lstadd_back(&lst, ft_lstnew(NULL));
		lst = lst -> next;
	}
	ptr = (char *) calloc(i + 1, 1);
	lst = ret;
	while (lst)
	{
		ft_strlcat(ptr, lst -> content, i + 1);
		lst = lst -> next;
	}
	ft_lstclear(&ret, free);
	return (ptr);
}
