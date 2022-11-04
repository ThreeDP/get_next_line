/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:00 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/30 15:32:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_list	*ft_lstnew(char *content, size_t buf_read)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> buf_read = buf_read;
	head -> next = NULL;
	return (head);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tail;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tail = lst;
		lst = lst -> next;
	}
	return (tail);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!lst || !new)
		return ;
	tail = ft_lstlast(*lst);
	if (tail == NULL)
		*lst = new;
	else
		tail -> next = new;
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
