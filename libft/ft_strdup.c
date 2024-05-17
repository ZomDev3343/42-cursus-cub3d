/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:18:23 by truello           #+#    #+#             */
/*   Updated: 2024/04/01 15:20:25 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = -1;
	if (!str)
		return (NULL);
	res = (char *) ft_calloc(ft_strlen(str), 1);
	if (!res)
		return (NULL);
	while (str[++i])
		res[i] = str[i];
	return (res);
}
