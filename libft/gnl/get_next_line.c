/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2024/07/09 13:56:02 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Returns the index of the first newline character if found
	in the string, else returns 0
*/
static int	is_line(char *str, ssize_t read_size)
{
	ssize_t	i;

	i = 0;
	while (i < read_size)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

/* Returns the total length of the gotten line */
static ssize_t	get_line_length(t_list *line)
{
	ssize_t	len;
	ssize_t	newline_idx;
	t_list	*cur;

	cur = line;
	len = 0;
	if (!line)
		return (0);
	while (cur)
	{
		newline_idx = is_line(cur->data, cur->read_size);
		if (newline_idx >= 0)
			return (len + newline_idx + 1);
		else
			len += cur->read_size;
		cur = cur->next;
	}
	return (len);
}

/* Fill the buffer with all the characters to form the line string*/
char	*make_line(t_list *lst, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	char	*res;

	if (len == 0 || !lst)
		return (NULL);
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < lst->read_size && i + j < len)
		{
			res[i + j] = (lst->data)[j];
			j++;
		}
		lst = lst->next;
		i += j;
	}
	return (res);
}

/* Returns the well-formed read line and
	creates the remaining string node
*/
static char	*process_list(t_list **lst)
{
	char	*res;
	ssize_t	line_len;
	t_list	*remain;
	t_list	*last;
	ssize_t	nl_idx;

	remain = NULL;
	line_len = get_line_length(*lst);
	res = make_line(*lst, line_len);
	if (!res || !*lst)
		return (NULL);
	last = *lst;
	while (last->next)
		last = last->next;
	nl_idx = is_line(last->data, last->read_size);
	if (nl_idx >= 0 && nl_idx < last->read_size - 1)
		remain = lstnew(strdupl(last->data, last->read_size, nl_idx + 1),
				last->read_size - nl_idx - 1);
	lst_clear(lst);
	if (remain)
		lst_push_back(lst, remain);
	return (res);
}

/* Main function to do the get_next_line */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			rs;
	t_list			*new_elem;

	if (fd == -1)
		return (NULL);
	if (line && is_line(line->data, line->read_size) >= 0)
		return (process_list(&line));
	readline = (char *) malloc(BUFFER_SIZE);
	if (!readline)
		return (NULL);
	rs = read(fd, readline, BUFFER_SIZE);
	while (rs > 0)
	{
		new_elem = lstnew(strdupl(readline, rs, 0), rs);
		lst_push_back(&line, new_elem);
		if (is_line(readline, rs) >= 0)
			break ;
		rs = read(fd, readline, BUFFER_SIZE);
	}
	free(readline);
	if (rs == -1)
		lst_clear(&line);
	return (process_list(&line));
}
