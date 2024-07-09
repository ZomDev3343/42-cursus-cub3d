/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2024/07/09 13:44:43 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Creates a new list element */
t_list	*lstnew(char *data, ssize_t read_size)
{
	t_list	*res;

	res = (t_list *) malloc(sizeof(t_list));
	if (!res || !data || read_size == 0)
		return (NULL);
	res->data = data;
	res->read_size = read_size;
	res->next = NULL;
	return (res);
}

/* Make a duplicate of a char buffer
	(not a well formed string)
*/
char	*strdupl(char *str, ssize_t read_size, ssize_t start)
{
	char	*res;
	ssize_t	i;

	i = start;
	if (!str || start < 0 || read_size <= 0 || start >= read_size)
		return (NULL);
	res = (char *) malloc(read_size - start);
	if (!res)
		return (NULL);
	while (i < read_size)
	{
		res[i - start] = (unsigned char) str[i];
		i++;
	}
	return (res);
}

/* Adds an element at the end of a list */
void	lst_push_back(t_list **head, t_list *elem)
{
	t_list	*cur;

	if (!elem)
		return ;
	if (!*head)
	{
		*head = elem;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
}

/* Clears a list */
void	lst_clear(t_list **head)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->data);
		free(cur);
		cur = tmp;
	}
	*head = NULL;
}

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
