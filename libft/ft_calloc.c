/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:13:51 by truello           #+#    #+#             */
/*   Updated: 2024/03/13 18:09:54 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	r = malloc(count * size);
	if (!r)
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *) r)[i] = 0;
		i++;
	}
	return (r);
}

int	ft_free(void *ptr)
{
	if (ptr)
		return (free(ptr), 1);
	return (0);
}
