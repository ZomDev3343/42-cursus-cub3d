/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:02:39 by truello           #+#    #+#             */
/*   Updated: 2024/02/08 12:36:28 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#define FT_READ_BUFFER_SIZE 1024

int	get_file_size(char *file_path)
{
	int		fd;
	char	buf[FT_READ_BUFFER_SIZE];
	int		read_bytes;
	int		sum;

	read_bytes = 1;
	sum = 0;
	fd = open(file_path, O_RDONLY);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, FT_READ_BUFFER_SIZE);
		if (read_bytes > 0)
			sum += read_bytes;
	}
	close(fd);
	return (sum);
}

char	*get_file_content(char *file_path)
{
	char	*content;
	int		file_size;
	int		fd;
	int		bytes_read;
	int		tmp_bytes;

	bytes_read = 0;
	tmp_bytes = 1;
	file_size = get_file_size(file_path);
	content = (char *) ft_calloc(file_size + 1, 1);
	if (!content)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	while (tmp_bytes > 0 && bytes_read < file_size)
	{
		tmp_bytes = read(fd, content + bytes_read, 1);
		if (tmp_bytes > 0)
			bytes_read += tmp_bytes;
	}
	close(fd);
	return (content);
}
