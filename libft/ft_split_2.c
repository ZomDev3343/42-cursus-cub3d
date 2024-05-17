/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:48 by tohma             #+#    #+#             */
/*   Updated: 2024/04/18 14:03:22 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_parts_size(char **parts)
{
	int	i;

	if (!parts || !*parts)
		return (0);
	i = 0;
	while (parts[i])
		i++;
	return (i);
}

void	print_parts(char **parts)
{
	int	i;

	i = -1;
	if (!parts)
		return ;
	while (parts[++i])
		printf("%s\n", parts[i]);
}
