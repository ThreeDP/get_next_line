/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:00 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/06 19:17:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	cached_c;

	i = 0;
	cached_c = (char)c;
	while (str[i] && str[i] != cached_c)
		i++;
	if (str[i] == cached_c)
		return (&((char *)str)[i]);
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

void	ft_lstadd_back(t_list **lst, int creat_lst)
{
	t_list	*tail;
	t_list	*head;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new -> content = NULL;
	new -> next = NULL;
	if (!creat_lst)
	{
		head = *lst;
		while (head)
		{
			tail = head;
			head = head->next;
		}
		tail -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	head = *lst;
	next = *lst;
	while (next)
	{
		head = head -> next;
		del(next -> content);
		free(next);
		next = head;
	}
	*lst = NULL;
}
