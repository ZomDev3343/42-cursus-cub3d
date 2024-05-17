/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:37:21 by truello           #+#    #+#             */
/*   Updated: 2024/03/13 18:07:34 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/* Split the given line and returns if all the parts contain int values */
int	has_int_parts(char *line, char delimiter)
{
	char	**parts;
	int		i;

	i = -1;
	parts = ft_split(line, delimiter);
	while (parts[++i])
		if (!ft_strncmp(parts[i], "0", 1) && ft_atoi(parts[i]) == 0)
			return (free_parts(parts), FALSE);
	free_parts(parts);
	return (TRUE);
}

/* Doesnt free 'parts' */
int	is_int_parts(char **parts)
{
	int		i;

	i = -1;
	while (parts[++i])
		if (!ft_strncmp(parts[i], "0", 1) && ft_atoi(parts[i]) == 0)
			return (FALSE);
	return (TRUE);
}
